#pragma once

#include "config.hpp"

/*
class to represent the client with
- ressources
- camera
- fog of war
- states
*/


class Player {
public:

	void Load()
	{
		m_id = -1; // set an unique thing but later

		for (int i = 1; i <= 3; i++) {
			m_ressources[i] = 0.f;
		}
	}

	int m_id;
	float GetLocalRessource(int ressource_type) {
		return m_ressources[ressource_type];
	}

	void SetLocalRessource(int ressource_type, float value) {
		m_ressources[ressource_type] = value;
	}

private:
	std::map<int, float> m_ressources; // to use with the enum RESSOURCE_TYPE, just cannot define here
};