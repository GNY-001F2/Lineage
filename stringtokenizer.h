/* stringtokenizer.h; defines a collection of functions to manipulate string
 * tokens
 * Copyright (C) 2016  Aayush Agarwal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include <string>
#include <vector>

namespace stringtokenizer {

/* converts an entered string into a vector of string tokens based on
 * the delimiter, with the default being a space.
 */
std::vector<std::string> tokenize(std::string source, char delimiter = ' ');

/* Take a string and character delimiter as input and convert them to vectors
 * of their corresponding numeric types.
 *
 * The default delimiter is a single white space.
 */
std::vector<int> sttoiv(std::string source, char delimiter = ' ');
std::vector<long> sttolv(std::string source, char delimiter = ' ');
std::vector<long long> sttollv(std::string source, char delimiter = ' ');

std::vector<unsigned long> sttoulv(std::string source, char delimiter = ' ');
std::vector<unsigned long long> sttoullv(std::string source,
                                         char delimiter = ' ');

std::vector<float> sttofv(std::string source, char delimiter = ' ');
std::vector<double> sttodv(std::string source, char delimiter = ' ');
std::vector<long double> sttoldv(std::string source, char delimiter = ' ');

/* Take a string vector as input and convert them to vectors of their
 * corresponding numeric types.
 */
std::vector<int> sttoiv(std::vector<std::string> tokens);
std::vector<long> sttolv(std::vector<std::string> tokens);
std::vector<long long> sttollv(std::vector<std::string> tokens);

std::vector<unsigned long> sttoulv(std::vector<std::string> tokens);
std::vector<unsigned long long> sttoullv(std::vector<std::string> tokens);

std::vector<float> sttofv(std::vector<std::string> tokens);
std::vector<double> sttodv(std::vector<std::string> tokens);
std::vector<long double> sttoldv(std::vector<std::string> tokens);

}

#endif
