#pragma once
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

class CSubstitutionTable
{
public:
	static std::vector<uint8_t> GenerateEncryptionTable(int key);
	static std::vector<uint8_t> GenerateDecryptionTable(int key);
};
