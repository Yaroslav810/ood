#include "CSubstitutionTable.h"

std::vector<uint8_t> CSubstitutionTable::GenerateEncryptionTable(int key)
{
	std::vector<uint8_t> data(256);
	std::iota(data.begin(), data.end(), 0);
	std::shuffle(data.begin(), data.end(), std::mt19937(key));
	return data;
}

std::vector<uint8_t> CSubstitutionTable::GenerateDecryptionTable(int key)
{
	auto encryptionTable = GenerateEncryptionTable(key);
	std::vector<uint8_t> data(256);
	for (size_t i = 0; i < encryptionTable.size(); ++i)
	{
		data[encryptionTable[i]] = i;
	}
	return data;
}
