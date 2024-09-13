#include <iostream>
#include <memory>
#include <algorithm>

#include "ICompressor.h"
#include "CompressionManager.h"
#include "CompressionManagerFactory.h"

CompressionManager::CompressionManager(std::unique_ptr<ICompressor> operation) : m_Operation(std::move(operation))
{
}

void CompressionManager::StartProgram()
{
    std::string operation, filePath;
    std::cout << "Chose operation: " << "\n";
    std::cout << "\t(C)ompress file" << "\n";
    std::cout << "\t(D)ecompress file" << "\n";
    std::cin >> operation;
    std::cout << "Path to file: " << "\n";
    std::cin >> filePath;

    std::ranges::transform(operation, operation.begin(), ::tolower);

    auto base = CompressionManagerFactory::CreateCompressionManager(operation, filePath);
    const auto manager = CompressionManager(std::move(base));
    manager.m_Operation->Process();
}
