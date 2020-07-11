#include <array>
#include <bitset>
#include <cctype>
#include <execution>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

struct Util {
    static const char* hex_char_to_bin(char c) {
        switch (toupper(c)) {
            case '0': return "0000";
            case '1': return "0001";
            case '2': return "0010";
            case '3': return "0011";
            case '4': return "0100";
            case '5': return "0101";
            case '6': return "0110";
            case '7': return "0111";
            case '8': return "1000";
            case '9': return "1001";
            case 'A': return "1010";
            case 'B': return "1011";
            case 'C': return "1100";
            case 'D': return "1101";
            case 'E': return "1110";
            case 'F': return "1111";
        }
    }

    static unsigned int hex_char_to_uint(char val) {
        std::stringstream ss;
        unsigned int num;
        ss << std::hex << val;
        ss >> num;
        return num;
    }

    static std::string uint_to_hex_string(unsigned int val) {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(sizeof(short)) << std::hex << val;
        return ss.str();
    }

    static unsigned int hex_string_to_uint(std::string&& val) {
        std::stringstream ss1;
        unsigned int num1;
        ss1 << std::hex << val;
        ss1 >> num1;
        return num1;
    }

    static const char* dec_to_base64(int val) {
        switch (val) {
            case 0:   return "A";
            case 1:   return "B";
            case 2:   return "C";
            case 3:   return "D";
            case 4:   return "E";
            case 5:   return "F";
            case 6:   return "G";
            case 7:   return "H";
            case 8:   return "I";
            case 9:   return "J";
            case 10:  return "K";
            case 11:  return "L";
            case 12:  return "M";
            case 13:  return "N";
            case 14:  return "O";
            case 15:  return "P";
            case 16:  return "Q";
            case 17:  return "R";
            case 18:  return "S";
            case 19:  return "T";
            case 20:  return "U";
            case 21:  return "V";
            case 22:  return "W";
            case 23:  return "X";
            case 24:  return "Y";
            case 25:  return "Z";
            case 26:  return "a";
            case 27:  return "b";
            case 28:  return "c";
            case 29:  return "d";
            case 30:  return "e";
            case 31:  return "f";
            case 32:  return "g";
            case 33:  return "h";
            case 34:  return "i";
            case 35:  return "j";
            case 36:  return "k";
            case 37:  return "l";
            case 38:  return "m";
            case 39:  return "n";
            case 40:  return "o";
            case 41:  return "p";
            case 42:  return "q";
            case 43:  return "r";
            case 44:  return "s";
            case 45:  return "t";
            case 46:  return "u";
            case 47:  return "v";
            case 48:  return "w";
            case 49:  return "x";
            case 50:  return "y";
            case 51:  return "z";
            case 52:  return "0";
            case 53:  return "1";
            case 54:  return "2";
            case 55:  return "3";
            case 56:  return "4";
            case 57:  return "5";
            case 58:  return "6";
            case 59:  return "7";
            case 60:  return "8";
            case 61:  return "9";
            case 62:  return "+";
            case 63:  return "/";
        }
    }

    static int base64_to_dec(char val) {
        switch (val) {
            case 'A': return 0;
            case 'B': return 1;
            case 'C': return 2;
            case 'D': return 3;
            case 'E': return 4;
            case 'F': return 5;
            case 'G': return 6;
            case 'H': return 7;
            case 'I': return 8;
            case 'J': return 9;
            case 'K': return 10;
            case 'L': return 11;
            case 'M': return 12;
            case 'N': return 13;
            case 'O': return 14;
            case 'P': return 15;
            case 'Q': return 16;
            case 'R': return 17;
            case 'S': return 18;
            case 'T': return 19;
            case 'U': return 20;
            case 'V': return 21;
            case 'W': return 22;
            case 'X': return 23;
            case 'Y': return 24;
            case 'Z': return 25;
            case 'a': return 26;
            case 'b': return 27;
            case 'c': return 28;
            case 'd': return 29;
            case 'e': return 30;
            case 'f': return 31;
            case 'g': return 32;
            case 'h': return 33;
            case 'i': return 34;
            case 'j': return 35;
            case 'k': return 36;
            case 'l': return 37;
            case 'm': return 38;
            case 'n': return 39;
            case 'o': return 40;
            case 'p': return 41;
            case 'q': return 42;
            case 'r': return 43;
            case 's': return 44;
            case 't': return 45;
            case 'u': return 46;
            case 'v': return 47;
            case 'w': return 48;
            case 'x': return 49;
            case 'y': return 50;
            case 'z': return 51;
            case '0': return 52;
            case '1': return 53;
            case '2': return 54;
            case '3': return 55;
            case '4': return 56;
            case '5': return 57;
            case '6': return 58;
            case '7': return 59;
            case '8': return 60;
            case '9': return 61;
            case '+': return 62;
            case '/': return 63;
        }
    }

    
    static std::string read_file(const std::string& filename) {
        std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file!");
        }

        std::streampos size = file.tellg();
        if (size == -1) {
            throw std::runtime_error("Could not read from file!");
        }

        std::string buffer;
        buffer.resize(size);
        file.seekg(0);
        file.read(&buffer[0], size);
        file.close();

        return buffer;
    }

    static int calculate_hamming_distance(std::string val1, std::string val2) {
        // Add padding if the two strings are not of equal length
        while (val1.length() < val2.length()) {
            val1 += "0";
        }
        while (val2.length() < val1.length()) {
            val2 += "0";
        }

        int count = 0;
        for (size_t i = 0; i < val1.length(); i++) {
            unsigned int bin1 = val1.at(i);
            unsigned int bin2 = val2.at(i);

            unsigned int xord = bin1 ^ bin2;
            for (int i = 0; i < sizeof(unsigned int) * 2; i++) {
                if (xord & (1 << i)) {
                    count++;
                }
            }
        }

        return count;
    }
};

struct Exercise1 {
    /* https://www.quora.com/How-does-base64-encoding-work/answer/Rajesh-Prajapati-71 */
    static std::string convert_hex_to_base64(std::string input) {
        std::string binary_input;
        for (std::string::iterator it = input.begin(); it < input.end(); it++) {
            binary_input += Util::hex_char_to_bin(*it);
        }

        // The text's length has to be a multiple of 6
        int padding = 0;
        while (binary_input.size() % 6 != 0) {
            binary_input += "00";
            padding++;
        }

        std::string result;
        for (size_t i = 0; i < binary_input.size(); i += 6) {
            std::string tmp = binary_input.substr(i, 6);
            int val = std::stoi(tmp, nullptr, 2);
            result += Util::dec_to_base64(val);
        }

        // All padded 0s need to be replaced with =
        while (padding > 0) {
            result += "=";
            padding--;
        }

        return result;
    }
};

struct Exercise2 {
    static std::string xor_hex_strings(std::string hex1, std::string hex2) {
        if (hex1.length() != hex2.length()) {
            throw std::runtime_error("String are not of the same length");
        }

        size_t length = hex1.length();
        std::string result;
        for (int i = 0; i < length; i++) {
            unsigned int num1 = Util::hex_char_to_uint(hex1.at(i));
            unsigned int num2 = Util::hex_char_to_uint(hex2.at(i));

            std::stringstream ss;
            ss << std::hex << (num1 ^ num2);
            result += ss.str();
        }

        return result;
    }
};

struct Exercise3 {
    struct Result {
        float score;
        std::string xorval;
        char xorchar;
        std::string text;
    };

    static Result decrypt(std::string input) {
        std::vector<Result> texts;

        // iterate over all decimal values of characters
        for (unsigned int xorval = 0; xorval < 255; xorval++) {
            std::string potential_result;
            std::stringstream ss_xorval;
            ss_xorval << std::hex << xorval;

            for (size_t i = 0; i < input.size(); i += 2) {
                unsigned int val = Util::hex_string_to_uint(input.substr(i, 2));
                unsigned int decrypt = val ^ xorval;

                // As decrypt would have value 2 for letter 'b' we need to shift it
                // to according to the ASCII table. As the value could therefore become
                // an unprintable character again, a modulo and another shift is needed
                // to make sure the character will be in the printable range between
                // 32 (0x20) and 126 (0x7e)
                //potential_result += (char)((decrypt + 96) % 127 + 31);
                potential_result += (char)(decrypt);
            }

            //if (is_printable(potential_result)) {
                float score = get_score(potential_result);
                //if (score > 200.0f) {
                    texts.push_back({ score, ss_xorval.str(), (char)xorval, potential_result });
                //}
            //}
        }

        sort_results(texts);

        return texts.size() ? texts.front() : Result();
    }

    static void sort_results(std::vector<Result>& texts) {
        std::sort(texts.begin(), texts.end(), [](Result r1, Result r2) {
            return r1.score > r2.score;
        });
    }

    static bool is_printable(std::string& data) {
        std::string text;
        std::transform(data.begin(), data.end(), std::back_inserter(text), [](unsigned char c) {
            return std::tolower(c);
        });

        bool is_printable = true;
        for (size_t i = 0; i < text.size(); i++) {
            int val = text.at(i);
            if (val < 0 || val > 255 || !isprint(val)) {
                return false;
            }
        }

        return true;
    }

    static float get_score(std::string& data) {
        std::string text;
        std::transform(data.begin(), data.end(), std::back_inserter(text), [](unsigned char c) {
            return std::tolower(c);
        });

        /* https://en.wikipedia.org/wiki/Letter_frequency */
        std::unordered_map<char, float> letter_frequency = {
            { 'a',  8.167f },
            { 'b',  1.492f },
            { 'c',  2.782f },
            { 'd',  4.253f },
            { 'e', 12.702f },
            { 'f',  2.228f },
            { 'g',  2.015f },
            { 'h',  6.094f },
            { 'i',  6.966f },
            { 'j',  0.153f },
            { 'k',  0.772f },
            { 'l',  4.025f },
            { 'm',  2.406f },
            { 'n',  6.749f },
            { 'o',  7.507f },
            { 'p',  1.929f },
            { 'q',  0.095f },
            { 'r',  5.987f },
            { 's',  6.327f },
            { 't',  9.056f },
            { 'u',  2.758f },
            { 'v',  0.978f },
            { 'w',  2.360f },
            { 'x',  0.150f },
            { 'y',  1.974f },
            { 'z',  0.074f },
            { ' ', 13.000f },
        };

        float score = 0.0f;
        std::for_each(text.begin(), text.end(), [&score, letter_frequency](char c) {
            if (letter_frequency.find(c) != letter_frequency.end())
                score += letter_frequency.at(c);
        });

        return score;
    }
};

struct Exercise4 {
    static Exercise3::Result decrypt(std::string filepath) {
        std::string file_content = Util::read_file(filepath);

        size_t start;
        size_t end = 0;
        std::vector<std::string> lines;
        do {
            start = file_content.find_first_not_of("\r\n", 0);
            end = file_content.find("\r\n", start);
            lines.push_back(file_content.substr(start, end - start));
            // Remove the line after extracting it. Otherwise we would have an integer
            // overflow of start and end at some point of processing.
            // Remove characters until end+2 to include the line ending \r\n as well.
            file_content.erase(start, end + 2);
        } while (file_content.length() > 0);

        // Decrypt every line like already done in exercise 3
        std::vector<Exercise3::Result> texts;
        for (auto it = lines.begin(); it < lines.end(); it++) {
            auto tmp = Exercise3::decrypt(*it);
            if (tmp.score > 0.0f) {
                texts.push_back(tmp);
            }
        }

        Exercise3::sort_results(texts);

        return texts.size() ? texts.front() : Exercise3::Result();
    }
};

struct Exercise5 {
    static std::string encrypt(std::string input, std::string key) {
        std::vector<int> keys;
        for (auto it = key.begin(); it < key.end(); it++) {
            keys.push_back((int)(*it));
        }
        int position = 0;

        std::string result;
        for (size_t i = 0; i < input.size(); i++) {
            unsigned int val = input.at(i);
            result += Util::uint_to_hex_string(val ^ keys[position]);
            position = (position + 1) % keys.size();
        }

        return result;
    }
};

struct Exercise6 {
    struct PossibleKeyLength {
        int keysize;
        float avg_distance;
    };

    struct Result {
        std::string key;
        float score;
        std::string text;
    };

    static Result decrypt(std::string filepath) {
        std::string file_content = Util::read_file(filepath);

        // Distance between those two test strings should be 37
        //std::string str1 = "this is a test";
        //std::string str2 = "wokka wokka!!!";
        //int diff = Util::calculate_hamming_distance(str1, str2);

        // Convert from base64 to hex first
        while (file_content.at(file_content.length() - 1) == '=') {
            file_content.erase(file_content.length() - 1);
        }
        std::vector<int> decimal_contents;
        for (auto it = file_content.begin(); it < file_content.end(); it++) {
            decimal_contents.push_back(Util::base64_to_dec(*it));
        }
        std::string bin_content;
        for (auto it = decimal_contents.begin(); it < decimal_contents.end(); it++) {
            bin_content += std::bitset<6>(*it).to_string();
        }
        std::string hex_content;
        for (int i = 0; i < bin_content.length(); i += 4) {
            std::string tmp = bin_content.substr(i, 4);
            int val = std::stoi(tmp, nullptr, 2);
            std::stringstream ss;
            ss << std::hex << val;
            hex_content += ss.str();
        }
        
        // Guess the key
        std::vector<PossibleKeyLength> avg_distances;
        for (int keysize = 2; keysize <= 40; keysize++) {
            int ks = keysize * 2;

            auto chunk1 = hex_content.substr(0, ks);
            auto chunk2 = hex_content.substr(ks, ks * 2);
            auto chunk3 = hex_content.substr(ks * 2, ks * 3);
            auto chunk4 = hex_content.substr(ks * 3, ks * 4);
            auto normalized_distance = (float)(Util::calculate_hamming_distance(chunk1, chunk2)) / ks +
                (float)(Util::calculate_hamming_distance(chunk2, chunk3)) / ks +
                (float)(Util::calculate_hamming_distance(chunk3, chunk4)) / ks +
                (float)(Util::calculate_hamming_distance(chunk1, chunk3)) / ks +
                (float)(Util::calculate_hamming_distance(chunk1, chunk4)) / ks +
                (float)(Util::calculate_hamming_distance(chunk2, chunk4)) / ks;

            avg_distances.push_back({ keysize, normalized_distance / 6 });
        }

        // Get the keysize with the lowest distance
        std::sort(avg_distances.begin(), avg_distances.end(), [](PossibleKeyLength pk1, PossibleKeyLength pk2) {
            return pk1.avg_distance < pk2.avg_distance;
        });

        std::vector<PossibleKeyLength> possible_key_lengths;
        for (int i = 0; i < 3; i++) {
            possible_key_lengths.push_back(avg_distances.at(i));
        }

        std::vector<Result> possible_results;
        for (auto possibley_key_length : possible_key_lengths) {
            std::string key;
            for (int i = 0; i < possibley_key_length.keysize; i++) {
                std::string block;
                for (int j = i; j * 2 < hex_content.size(); j += possibley_key_length.keysize) {
                    block += hex_content.substr(j * 2, 2);
                }
                auto tmp = Exercise3::decrypt(block);
                key += tmp.xorchar;
            }
            
            auto _tmp_result = encrypt(hex_content, key);
            std::string _tmp_result_str;
            for (size_t i = 0; i < _tmp_result.length(); i += 2) {
                _tmp_result_str += (char) Util::hex_string_to_uint(_tmp_result.substr(i, 2));
            }
            float score = Exercise3::get_score(_tmp_result_str);
            possible_results.push_back({ key, score, _tmp_result_str });
        }

        std::sort(possible_results.begin(), possible_results.end(), [](Result r1, Result r2) {
            return r1.score > r2.score;
        });

        // Theoretically we would also need to look into the results and favor the shorter key when
        // two entries have the exact same score
        return possible_results.at(0);
    }

    static std::string encrypt(std::string input, std::string key) {
        std::vector<int> keys;
        for (auto it = key.begin(); it < key.end(); it++) {
            keys.push_back((int)(*it));
        }
        int position = 0;

        std::string result;
        for (size_t i = 0; i < input.size(); i += 2) {
            unsigned int val = (char) Util::hex_string_to_uint(input.substr(i, 2).c_str());
            result += Util::uint_to_hex_string(val ^ keys[position]);
            position = (position + 1) % keys.size();
        }

        return result;
    }
};

int main(void) {
    // SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ubw==
    std::string exercise1 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f";
    auto result1 = Exercise1::convert_hex_to_base64(exercise1);
    std::cout << "Solution 1: " << result1 << std::endl;

    // 746865206b696420646f6e277420706c6179
    std::string exercise2_1 = "1c0111001f010100061a024b53535009181c";
    std::string exercise2_2 = "686974207468652062756c6c277320657965";
    auto result2 = Exercise2::xor_hex_strings(exercise2_1, exercise2_2);
    std::cout << "Solution 2: " << result2 << std::endl;

    // X (0x58) - Cooking MC's like a pound of bacon
    std::string exercise3 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    auto result3 = Exercise3::decrypt(exercise3);
    std::cout << "Solution 3: " << std::endl;
    std::cout << "\t" << result3.xorchar << " - " << result3.text << " (" << result3.score << ")" << std::endl;

    // 5 (0x35) - Now that the party is jumping\n
    std::string exercise4 = "E:\\code\\cryptopals\\cryptopals\\src\\04-exercise-hackme.txt";
    auto result4 = Exercise4::decrypt(exercise4);
    std::cout << "Solution 4: " << std::endl;
    std::cout << "\t" << result4.xorchar << " - " << result4.text << " (" << result4.score << ")" << std::endl;

    // 0121663c2723682d232f26282626282f6f32202a661d212f3e2a343b2a663f2e35682c342d2e322d2b68681b2e213c66202e356822272c2a66296f2a273b66272966382a293823236839233a36662921213a3666292122682d232d21663f26222d233f683d232f2e342c2a22682e35682e662a2e226822293e2a68
    std::string exercise5 = "In the beginning the Universe was created. This has made a lot of people very angry and been widely regarded as a bad move.";
    auto result5 = Exercise5::encrypt(exercise5, "HOF");
    std::cout << "Solution 5: " << result5 << std::endl;

    // AliceInWonderland - Alice was beginning to get very tired [...]
    std::string exercise6 = "E:\\code\\cryptopals\\cryptopals\\src\\06-exercise-repeated-xor.txt";
    auto result6 = Exercise6::decrypt(exercise6);
    std::cout << "Solution 6: " << std::endl;
    std::cout << "\t" << result6.key << " - " << result6.text << " (" << result6.score << ")" << std::endl;

    return 0;
}
