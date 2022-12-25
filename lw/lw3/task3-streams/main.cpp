#include "lib/Decorator/CDecryptInputStream/CDecryptInputStream.h"
#include "lib/Decorator/CEncryptOutputStream/CEncryptOutputStream.h"
#include "lib/InputStream/CFileInputStream/CFileInputStream.h"
#include "lib/OutputStream/CFileOutputStream/CFileOutputStream.h"
#include "unordered_map"
#include <iostream>
#include <memory>

enum class ArgumentType
{
	ENCRYPT,
	DECRYPT,
	COMPRESS,
	DECOMPRESS,
};

std::unordered_map<std::string, ArgumentType> mapArgs = {
	{ "--encrypt", ArgumentType::ENCRYPT },
	{ "--decrypt", ArgumentType::DECRYPT },
	{ "--compress", ArgumentType::COMPRESS },
	{ "--decompress", ArgumentType::DECOMPRESS }
};

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		std::cout << "Argc parse error! Syntax: [options] <input-file> <output-file>" << std::endl;
		return 1;
	}
	IInputDataStreamPtr input = std::make_unique<CFileInputStream>(argv[argc - 2]);
	IOutputDataStreamPtr output = std::make_unique<CFileOutputStream>(argv[argc - 1]);

	int index = 1;
	while (index < argc - 2)
	{
		auto option = argv[index];
		if (mapArgs.find(option) == mapArgs.end())
		{
			std::cout << "Available options: --encrypt, --decrypt, --compress, --decompress" << std::endl;
			return 1;
		}

		switch (mapArgs[option])
		{
		case ArgumentType::ENCRYPT: {
			index++;
			auto key = atoi(argv[index]);
			output = std::make_unique<CEncryptOutputStream>(std::move(output), key);
			std::cout << "ENCRYPT " << key << ";" << std::endl;
			break;
		}
		case ArgumentType::DECRYPT: {
			index++;
			auto key = atoi(argv[index]);
			input = std::make_unique<CDecryptInputStream>(std::move(input), key);
			std::cout << "DECRYPT " << key << ";" << std::endl;
			break;
		}
		case ArgumentType::COMPRESS: {
			std::cout << "COMPRESS" << std::endl;
			break;
		}
		case ArgumentType::DECOMPRESS: {
			std::cout << "DECOMPRESS" << std::endl;
			break;
		}
		default: {
			std::cout << "Unknown error" << std::endl;
			return 1;
		}
		}
		index++;
	}

	while (!input->IsEOF())
	{
		output->WriteByte(input->ReadByte());
	}

	return 0;
}
