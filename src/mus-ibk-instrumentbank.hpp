/**
 * @file  mus-ibk-instrumentbank.hpp
 * @brief Support for .IBK (Instrument Bank) files.
 *
 * Copyright (C) 2010-2015 Adam Nielsen <malvineous@shikadi.net>
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

#ifndef _CAMOTO_GAMEMUSIC_PATCHBANK_FMT_IBK_HPP_
#define _CAMOTO_GAMEMUSIC_PATCHBANK_FMT_IBK_HPP_

#include <camoto/gamemusic/musictype.hpp>

namespace camoto {
namespace gamemusic {

/// Interface to an .IBK (Instrument Bank) file.
class MusicType_IBK: virtual public MusicType
{
	public:
		virtual std::string getCode() const;
		virtual std::string getFriendlyName() const;
		virtual std::vector<std::string> getFileExtensions() const;
		virtual unsigned long getCaps() const;
		virtual Certainty isInstance(stream::input_sptr input) const;
		virtual MusicPtr read(stream::input_sptr input, SuppData& suppData) const;
		virtual void write(stream::output_sptr output, SuppData& suppData,
			MusicPtr music, unsigned int flags) const;
		virtual SuppFilenames getRequiredSupps(stream::input_sptr input,
			const std::string& filenameMusic) const;
		virtual Metadata::MetadataTypes getMetadataList() const;
};

} // namespace gamemusic
} // namespace camoto

#endif // _CAMOTO_GAMEMUSIC_PATCHBANK_FMT_IBK_HPP_
