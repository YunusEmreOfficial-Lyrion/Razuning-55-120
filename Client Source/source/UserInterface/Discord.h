#pragma once
#include "StdAfx.h"
#include "PythonCharacterManager.h"
#include "PythonBackground.h"
#include "PythonPlayer.h"
#include "PythonGuild.h"

namespace Discord
{
	inline constexpr auto DiscordClientID = "1072524000237981717";

	using DCDATA = std::pair<std::string, std::string>;
	

	/*NAME*/
	inline DCDATA GetNameData()
	{
		/*Map Name*/
		auto WarpName = std::string(CPythonBackground::Instance().GetWarpMapName());

		//atlasinfo.txt
		static const std::map<std::string, std::string> m_MapName {
			{ "metin2_map_a1", "Yongan" },
			{ "metin2_map_b1", "Joan" },
			{ "metin2_map_c1", "Pyungmoo" },
		};

		auto MapName = "Konum: " + (m_MapName.count(WarpName) ? m_MapName.at(WarpName) : WarpName);

		/*CH Name*/
		auto CHName = "İsim: " + std::string(CPythonPlayer::Instance().GetName());
		std::string GuildName;
		if (CPythonGuild::Instance().GetGuildName(CPythonPlayer::Instance().GetGuildID(), &GuildName))
			CHName += "-Lonca: " + GuildName;

		return { MapName, CHName };
	}

	/*RACE*/
	inline DCDATA GetRaceData()
	{
		auto pInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
		if (!pInstance)
			return { "","" };

		const auto RACENUM = pInstance->GetRace();

		/*Image*/
		auto RaceImage = "race_" + std::to_string(RACENUM);

		/*Name*/
		auto RaceName = "";
		switch (RACENUM)
		{
		case NRaceData::JOB_WARRIOR:
		case NRaceData::JOB_WARRIOR + 4:
			RaceName = "Savaşçı";
			break;
		case NRaceData::JOB_ASSASSIN:
		case NRaceData::JOB_ASSASSIN + 4:
			RaceName = "Ninja";
			break;
		case NRaceData::JOB_SURA:
		case NRaceData::JOB_SURA + 4:
			RaceName = "Sura";
			break;
		case NRaceData::JOB_SHAMAN:
		case NRaceData::JOB_SHAMAN + 4:
			RaceName = "Şaman";
			break;
/*#if defined(ENABLE_WOLFMAN_CHARACTER)
		case NRaceData::JOB_WOLFMAN +:
			RaceName = "Lycan";
#endif*/
		}
		return { RaceImage , RaceName };
	}

	/*EMPIRE*/
	inline DCDATA GetEmpireData()
	{
		auto pInstance = CPythonCharacterManager::Instance().GetMainInstancePtr();
		if (!pInstance)
			return { "","" };

		const auto EmpireID = pInstance->GetEmpireID();

		/*Image*/
		auto EmpireImage = "empire_" + std::to_string(EmpireID);

		/*Name*/
		auto EmpireName = "";
		switch (EmpireID)
		{
		case 1:
			EmpireName = "(Shinsoo) Kırmızı Bayrak";
			break;
		case 2:
			EmpireName = "(Chunjo) Sarı Bayrak";
			break;
		case 3:
			EmpireName = "(Jinno) Mavi Bayrak";
		}
		return { EmpireImage, EmpireName};
	}
}