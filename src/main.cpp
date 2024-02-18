#include <argparse/argparse.hpp>
#include <memory>
#include <fstream>
#include <filesystem>
#include <renderware_binary_stream.h>
#include <iomanip>

std::shared_ptr<const argparse::ArgumentParser> parse_arguments(int argc, char* argv[])
{
    auto parser = std::make_shared<argparse::ArgumentParser>("rwconvert");

    parser->add_argument("input")
        .help("RenderWare file to convert");

    try
    {
        parser->parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << *parser << std::endl;
        exit(1);
    }

    return parser;
}

int main(int argc, char* argv[])
{
    auto arguments = parse_arguments(argc, argv);
    std::filesystem::path input(arguments->get("input"));

    std::ifstream input_stream(input, std::ios::binary);
    if (!input_stream)
    {
        std::cerr << "Failed to open " << input << std::endl;
    }

    kaitai::kstream ks(&input_stream);
    renderware_binary_stream_t rw(&ks);

    std::cout << "RenderWare version: " << std::hex << rw.version() << std::dec << std::endl;
    
    return 0;
}
