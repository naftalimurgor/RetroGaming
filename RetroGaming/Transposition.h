/*
	This file is part of {{ RetroGaming }}.

	Copyright [2019] [Justin LeCheminant]

	Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 */

#pragma once

#include <map>

#include "GameBase.h"

class Transposition :
	public GameBase
{
public:
	Transposition();
	~Transposition();

	void Play() override;

	void UpdateOffset(int offset = 0);

private:
	string EncryptString(string original);
	string DecryptString(string original);

	void EncryptFile(string file, string destination);
	void DecryptFile(string file);

	char GetEncryptedLetter(char letter);

	void BuildEncryptionMap();

	map<char, char> _encryptionMap;

	int _offset;

};
