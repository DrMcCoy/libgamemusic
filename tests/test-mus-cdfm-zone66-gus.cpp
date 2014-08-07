/**
 * @file   test-mus-cdfm-zone66-gus.cpp
 * @brief  Test code for GUS variant of Zone 66 CDFM files.
 *
 * Copyright (C) 2010-2014 Adam Nielsen <malvineous@shikadi.net>
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

#include "test-music.hpp"
#include "../src/mus-cdfm-zone66-gus.hpp"

class test_cdfm_zone66_gus: public test_music
{
	public:
		test_cdfm_zone66_gus()
		{
			this->type = "cdfm-zone66-gus";
			this->outputWidth = 0x10;
			this->numInstruments = 1;
			this->indexInstrumentOPL = -1;
			this->indexInstrumentMIDI = -1;
			this->indexInstrumentPCM = 0;
		}

		void addTests()
		{
			this->test_music::addTests();

			ADD_MUSIC_TEST(&test_cdfm_zone66_gus::test_volume_to_velocity);

			// c00: Normal
			this->isInstance(MusicType::DefinitelyYes, this->standard());

			// c01: Sample data past EOF
			this->isInstance(MusicType::DefinitelyNo, STRING_WITH_NULLS(
				"\x35\x01\x00\x00"
				"\xCC" "\x03" "\x02" "\x01" "\x01"
				"\x00\x00\x01"
				"\x00\x00\x00\x00"
				"\x0B\x00\x00\x00"
				"\x02\x00\x21\x00\x00\x00\x00\x10\x00\x00\x00"
				// Pattern 0
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// Pattern 1
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// PCM inst 1 sample data
				"\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0"
			));

			// c02: Loop target is past end of song
			this->isInstance(MusicType::DefinitelyNo, STRING_WITH_NULLS(
				"\x35\x00\x00\x00"
				"\xCC" "\x03" "\x02" "\x01" "\x0F"
				"\x00\x00\x01"
				"\x00\x00\x00\x00"
				"\x0B\x00\x00\x00"
				"\x02\x00\x21\x00\x00\x00\x00\x10\x00\x00\x00"
				// Pattern 0
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// Pattern 1
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// PCM inst 1 sample data
				"\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0"
			));

			// c03: Sequence specifies invalid pattern
			this->isInstance(MusicType::DefinitelyNo, STRING_WITH_NULLS(
				"\x35\x00\x00\x00"
				"\xCC" "\x03" "\x02" "\x01" "\x01"
				"\x00\x0F\x01"
				"\x00\x00\x00\x00"
				"\x0B\x00\x00\x00"
				"\x02\x00\x21\x00\x00\x00\x00\x10\x00\x00\x00"
				// Pattern 0
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// Pattern 1
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// PCM inst 1 sample data
				"\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0"
			));

			// c04: Pattern data offset is past EOF
			this->isInstance(MusicType::DefinitelyNo, STRING_WITH_NULLS(
				"\x35\x00\x00\x00"
				"\xCC" "\x03" "\x02" "\x01" "\x01"
				"\x00\x00\x01"
				"\x00\x00\x00\x00"
				"\xFF\x00\x00\x00"
				"\x02\x00\x21\x00\x00\x00\x00\x10\x00\x00\x00"
				// Pattern 0
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// Pattern 1
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// PCM inst 1 sample data
				"\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0"
			));
		}

		virtual std::string standard()
		{
			return STRING_WITH_NULLS(
				"\x35\x00\x00\x00"
				"\xCC" "\x03" "\x02" "\x01" "\x01"
				"\x00\x00\x01"
				"\x00\x00\x00\x00"
				"\x0B\x00\x00\x00"
				"\x02\x00\x21\x00\x00\x00\x00\x10\x00\x00\x00"
				// Pattern 0
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// Pattern 1
				"\x40\x23\x0F\x00\x01\x01\x00\x01\x80\x00\x02"
				// PCM inst 1 sample data
				"\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0\x00\x10\x00\xF0"
			);
		}

		void test_volume_to_velocity()
		{
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity( 0),   0);
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity( 1),   5);
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity( 8),  63);
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity(12), 127);
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity(14), 191);
			BOOST_REQUIRE_EQUAL(z66_volume_to_velocity(15), 255);
			return;
		}
};

IMPLEMENT_TESTS(cdfm_zone66_gus);
