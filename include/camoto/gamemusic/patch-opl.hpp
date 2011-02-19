/**
 * @file   patch-opl.hpp
 * @brief  Derived Patch for OPL patches.
 *
 * Copyright (C) 2010-2011 Adam Nielsen <malvineous@shikadi.net>
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

#ifndef _CAMOTO_GAMEMUSIC_PATCH_OPL_HPP_
#define _CAMOTO_GAMEMUSIC_PATCH_OPL_HPP_

#include <camoto/gamemusic/patch.hpp>
#include <camoto/types.hpp>

namespace camoto {
namespace gamemusic {

/// Descendent of Patch for storing OPL instrument settings.
struct OPLOperator {

	/// Default constructor sets everything to zero/defaults.
	OPLOperator()
		throw ();

	/// Is tremolo enabled?
	bool enableTremolo;

	/// Vibrato enabled.
	bool enableVibrato;

	/// Sustain enabled.
	bool enableSustain;

	/// KSR enabled.
	bool enableKSR;

	/// The frequency multiplication factor.
	uint8_t freqMult;

	/// The key scale level.
	uint8_t scaleLevel;

	/// The output level.
	uint8_t outputLevel;

	/// The attack rate.
	uint8_t attackRate;

	/// The decay rate.
	uint8_t decayRate;

	/// The sustain rate.
	uint8_t sustainRate;

	/// The release rate.
	uint8_t releaseRate;

	/// The waveform select.
	uint8_t waveSelect;

};

/// Descendent of Patch for storing OPL instrument settings.
struct OPLPatch: public Patch {

	/// Default constructor sets everything to zero/defaults.
	OPLPatch()
		throw ();

	/// Carrier settings.
	OPLOperator c;

	/// Modulator settings.
	OPLOperator m;

	/// The feedback modulation factor for the channel.
	uint8_t feedback;

	/// The synth type connection.
	bool connection;

	/// Rhythm mode instrument.
	/**
	 * 0 == normal instrument (c and m valid)
	 * 1 == hihat (m only)
	 * 2 == top cymbal (c only)
	 * 3 == tom tom (m only)
	 * 4 == snare drum (c only)
	 * 5 == bass drum (c and m)
	 */
	uint8_t rhythm;

	/// Increase tremolo depth.  NOTE: Affects all channels/instruments.
	bool deepTremolo;

	/// Increase vibrato depth.  NOTE: Affects all channels/instruments.
	bool deepVibrato;

};

inline bool operator== (const OPLOperator& a, const OPLOperator& b)
{
	return
		(a.enableTremolo == b.enableTremolo)
		&& (a.enableVibrato == b.enableVibrato)
		&& (a.enableSustain == b.enableSustain)
		&& (a.enableKSR == b.enableKSR)
		&& (a.freqMult == b.freqMult)
		&& (a.scaleLevel == b.scaleLevel)
		//&& (a.outputLevel == b.outputLevel)  // changes for volume/velocity
		&& (a.attackRate == b.attackRate)
		&& (a.decayRate == b.decayRate)
		&& (a.sustainRate == b.sustainRate)
		&& (a.releaseRate == b.releaseRate)
		&& (a.waveSelect == b.waveSelect)
	;
}

inline bool operator== (const OPLPatch& a, const OPLPatch& b)
{
	if (a.rhythm != b.rhythm) return false;

	if ((
		(a.rhythm == 0) ||
		(a.rhythm == 1) ||
		(a.rhythm == 3) ||
		(a.rhythm == 5)
	) && (
		!(a.c == b.c)
	)) return false;  // carrier used and didn't match

	if ((
		(a.rhythm == 0) ||
		(a.rhythm == 2) ||
		(a.rhythm == 4) ||
		(a.rhythm == 5)
	) && (
		!(a.m == b.m)
	)) return false;  // modulator used and didn't match

	if ((
		(a.rhythm == 0) ||
		(a.rhythm == 5)
	) && (
		!(a.m.outputLevel == b.m.outputLevel)
	)) return false;  // mod output level different on a 2-op patch

	return
		(a.feedback == b.feedback)
		&& (a.connection == b.connection)
		&& (a.deepTremolo == b.deepTremolo)
		&& (a.deepVibrato == b.deepVibrato)
	;
}

/// Shared pointer to a Patch.
typedef boost::shared_ptr<OPLPatch> OPLPatchPtr;

} // namespace gamemusic
} // namespace camoto

#endif // _CAMOTO_GAMEMUSIC_PATCH_OPL_HPP_