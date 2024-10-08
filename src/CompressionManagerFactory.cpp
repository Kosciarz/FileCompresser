#include "CompressionManagerFactory.h"
#include <CompressionManager.h>
#include "ICompressor.h"
#include "FileCompressor.h"
#include "FileDecompressor.h"

#include <iostream>
#include <string>

enum class Operation
{
    Compress = "c",
    Decompress = "d",
};

std::unique_ptr<ICompressor> CompressionManagerFactory::CreateCompressionManager(
    const std::string& operation,
    const std::string& file_path
)
{
    switch (operation)
    {
    case Operation::Compress:
        return std::make_unique<FileCompressor>(file_path);
        break;
    case Operation::Decompress:
        return std::make_unique<FileDecompressor>(file_path);
        break;
    default:
        std::cerr << "Invalid operation!" << "\n";
        throw std::runtime_error("Invalid operation");
    }
}
