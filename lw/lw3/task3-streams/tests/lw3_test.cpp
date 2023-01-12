#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../lib/InputStream/CFileInputStream/CFileInputStream.h"
#include "../lib/InputStream/CMemoryInputStream/CMemoryInputStream.h"
#include "../lib/OutputStream/CFileOutputStream/CFileOutputStream.h"
#include "../lib/OutputStream/CMemoryOutputStream/CMemoryOutputStream.h"

const std::string INPUT_FILE = "test.txt";
const std::string OUTPUT_FILE = "test_output.txt";
const std::string EMPTY_FILE = "empty.txt";
const std::string NO_EXIST_FILE = "no_exist.txt";

std::string GetDataFromFile(std::string const& fileName)
{
	std::ifstream stream;
	stream.open(fileName);
	if (!stream.is_open())
	{
		throw std::ios_base::failure(fileName);
	}
	std::string result;
	std::string line;
	while (getline(stream, line))
	{
		result.append(line + '\n');
	}
	return result;
}

SCENARIO("Creating file streams")
{
	GIVEN("A existent file and a nonexistent file")
	{
		WHEN("Creating a stream with an existing file")
		{
			THEN("Input stream is being created successfully")
			{
				REQUIRE_NOTHROW(CFileInputStream(INPUT_FILE));
			}
		}

		WHEN("Creating a stream using a non-existing file")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(CFileInputStream(NO_EXIST_FILE), std::ios_base::failure);
			}
		}
	}
}

SCENARIO("Reading from file streams")
{
	GIVEN("Input stream with data")
	{
		auto ifstream = CFileInputStream(INPUT_FILE);

		WHEN("Reading byte from a stream")
		{
			THEN("The data is being read")
			{
				REQUIRE(ifstream.ReadByte() == 'A');
				REQUIRE(ifstream.ReadByte() == ' ');
				REQUIRE(ifstream.ReadByte() == 'b');
				REQUIRE(ifstream.ReadByte() == '\n');
				REQUIRE(ifstream.ReadByte() == 'c');
				REQUIRE(ifstream.ReadByte() == '\n');

				AND_WHEN("All data has been read")
				{
					THEN("The end of the file has been reached")
					{
						REQUIRE(ifstream.IsEOF());
					}
					AND_WHEN("Continue to read")
					{
						THEN("Throw std::ios_base::failure exception")
						{
							REQUIRE_THROWS_AS(ifstream.ReadByte(), std::ios_base::failure);
						}
					}
				}
			}
		}

		WHEN("Reading buffer from a stream")
		{
			auto size = 6;
			char buffer[size];

			THEN("All data is read")
			{
				REQUIRE(ifstream.ReadBlock(buffer, size) == size);
			}

			THEN("The buffer contains data 'A b\nc\n'")
			{
				REQUIRE(buffer[0] == 'A');
				REQUIRE(buffer[1] == ' ');
				REQUIRE(buffer[2] == 'b');
				REQUIRE(buffer[3] == '\n');
				REQUIRE(buffer[4] == 'c');
				REQUIRE(buffer[5] == '\n');
			}
		}

		WHEN("Reading data with overflow")
		{
			auto size = 6;
			char buffer[size];

			THEN("All data is read")
			{
				REQUIRE(ifstream.ReadBlock(buffer, 10) == size);
			}

			THEN("The buffer contains data 'A b\nc\n'")
			{
				REQUIRE(buffer[0] == 'A');
				REQUIRE(buffer[1] == ' ');
				REQUIRE(buffer[2] == 'b');
				REQUIRE(buffer[3] == '\n');
				REQUIRE(buffer[4] == 'c');
				REQUIRE(buffer[5] == '\n');
			}
		}
	}

	GIVEN("Input stream with empty data")
	{
		auto ifstream = CFileInputStream(EMPTY_FILE);

		WHEN("Reading data from a stream")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(ifstream.ReadByte(), std::ios_base::failure);
			}
		}
	}
}

SCENARIO("Reading from memory streams")
{
	GIVEN("Input stream with data")
	{
		std::vector<uint8_t> memory = { 'A', ' ', 'b', '\n', 'c', '\n' };
		auto imstream = CMemoryInputStream(memory);

		WHEN("Reading byte from a stream")
		{
			THEN("The data is being read")
			{
				REQUIRE(imstream.ReadByte() == 'A');
				REQUIRE(imstream.ReadByte() == ' ');
				REQUIRE(imstream.ReadByte() == 'b');
				REQUIRE(imstream.ReadByte() == '\n');
				REQUIRE(imstream.ReadByte() == 'c');
				REQUIRE(imstream.ReadByte() == '\n');

				AND_WHEN("All data has been read")
				{
					THEN("The end of the file has been reached")
					{
						REQUIRE(imstream.IsEOF());
					}
					AND_WHEN("Continue to read")
					{
						THEN("Throw std::ios_base::failure exception")
						{
							REQUIRE_THROWS_AS(imstream.ReadByte(), std::ios_base::failure);
						}
					}
				}
			}
		}

		WHEN("Reading buffer from a stream")
		{
			auto size = 6;
			char buffer[size];

			THEN("All data is read")
			{
				REQUIRE(imstream.ReadBlock(buffer, size) == size);
			}

			THEN("The buffer contains data 'A b\nc\n'")
			{
				REQUIRE(buffer[0] == 'A');
				REQUIRE(buffer[1] == ' ');
				REQUIRE(buffer[2] == 'b');
				REQUIRE(buffer[3] == '\n');
				REQUIRE(buffer[4] == 'c');
				REQUIRE(buffer[5] == '\n');
			}
		}

		WHEN("Reading data with overflow")
		{
			auto size = 6;
			char buffer[size];

			THEN("All data is read")
			{
				REQUIRE(imstream.ReadBlock(buffer, 10) == size);
			}

			THEN("The buffer contains data 'A b\nc\n'")
			{
				REQUIRE(buffer[0] == 'A');
				REQUIRE(buffer[1] == ' ');
				REQUIRE(buffer[2] == 'b');
				REQUIRE(buffer[3] == '\n');
				REQUIRE(buffer[4] == 'c');
				REQUIRE(buffer[5] == '\n');
			}
		}
	}

	GIVEN("Input stream with empty data")
	{
		auto imstream = CMemoryInputStream({});

		WHEN("Reading data from a stream")
		{
			THEN("An exception is thrown")
			{
				REQUIRE_THROWS_AS(imstream.ReadByte(), std::ios_base::failure);
			}
		}
	}
}

SCENARIO("Creating output streams")
{
	GIVEN("File title output")
	{
		WHEN("Creating a stream")
		{
			THEN("Output stream is being created successfully")
			{
				REQUIRE_NOTHROW(CFileOutputStream(OUTPUT_FILE));
			}
		}
	}
}

SCENARIO("Writing to file streams")
{
	GIVEN("Empty file")
	{
		auto ofstream = CFileOutputStream(OUTPUT_FILE);

		WHEN("Writing byte to a stream")
		{
			THEN("The data is being write")
			{
				REQUIRE_NOTHROW(ofstream.WriteByte('A'));
				REQUIRE_NOTHROW(ofstream.WriteByte(' '));
				REQUIRE_NOTHROW(ofstream.WriteByte('b'));
				REQUIRE_NOTHROW(ofstream.WriteByte('\n'));
				REQUIRE_NOTHROW(ofstream.WriteByte('c'));
				REQUIRE_NOTHROW(ofstream.WriteByte('\n'));

				AND_WHEN("Read the recorded file")
				{
					THEN("The contents of the file will remain as expected")
					{
						REQUIRE(GetDataFromFile(OUTPUT_FILE) == "A b\nc\n");
					}
				}
			}
		}

		WHEN("Writing buffer to a stream")
		{
			char buffer[6] = { 'A', ' ', 'b', '\n', 'c', '\n' };

			THEN("All data is write")
			{
				REQUIRE_NOTHROW(ofstream.WriteBlock(buffer, 6));

				AND_WHEN("Read the recorded file")
				{
					THEN("The buffer contains data 'A b\nc\n'")
					{
						REQUIRE(GetDataFromFile(OUTPUT_FILE) == "A b\nc\n");
					}
				}
			}
		}
	}
}

SCENARIO("Writing to memory streams")
{
	GIVEN("Empty memory")
	{
		std::vector<uint8_t> memory = {};
		auto ofstream = CMemoryOutputStream(memory);

		WHEN("Writing byte to a stream")
		{
			THEN("The data is being write")
			{
				REQUIRE_NOTHROW(ofstream.WriteByte('A'));
				REQUIRE_NOTHROW(ofstream.WriteByte(' '));
				REQUIRE_NOTHROW(ofstream.WriteByte('b'));
				REQUIRE_NOTHROW(ofstream.WriteByte('\n'));
				REQUIRE_NOTHROW(ofstream.WriteByte('c'));
				REQUIRE_NOTHROW(ofstream.WriteByte('\n'));

				AND_WHEN("Read the recorded memory")
				{
					THEN("The contents of the memory will remain as expected")
					{
						REQUIRE(memory[0] == 'A');
						REQUIRE(memory[1] == ' ');
						REQUIRE(memory[2] == 'b');
						REQUIRE(memory[3] == '\n');
						REQUIRE(memory[4] == 'c');
						REQUIRE(memory[5] == '\n');
					}
				}
			}
		}

		WHEN("Writing buffer to a stream")
		{
			char buffer[6] = { 'A', ' ', 'b', '\n', 'c', '\n' };

			THEN("All data is write")
			{
				REQUIRE_NOTHROW(ofstream.WriteBlock(buffer, 6));

				AND_WHEN("Read the recorded file")
				{
					THEN("The buffer contains data 'A b\nc\n'")
					{
						REQUIRE(memory[0] == 'A');
						REQUIRE(memory[1] == ' ');
						REQUIRE(memory[2] == 'b');
						REQUIRE(memory[3] == '\n');
						REQUIRE(memory[4] == 'c');
						REQUIRE(memory[5] == '\n');
					}
				}
			}
		}
	}
}
