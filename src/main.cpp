#include <argparse/argparse.hpp>
#include <memory>

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
    
    return 0;
}
