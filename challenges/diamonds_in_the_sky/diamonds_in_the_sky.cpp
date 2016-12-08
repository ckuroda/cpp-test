#include <iostream>

class Sky
{
protected:
	Sky(int stars = 0)
		: m_stars(stars)
	{}

	int stars() const
	{
		return m_stars;
	}

	void stars(int n)
	{
		m_stars = n;
	}

private:
	int m_stars;
};

class BlueSky : public Sky
{
public:
	BlueSky(int stars = 0)
		: Sky(stars)
	{}
};

class NightSky : public Sky
{
public:
	NightSky(int stars = 0)
		: Sky(stars)
	{}
};
// PROIBIDO ALTERAR
class BlueNightSky : public BlueSky, public NightSky
{
public:
	BlueNightSky()
	{}
};
// PROIBIDO ALTERAR
void readInput(NightSky& nightSky)
{
	int n = 0;
	std::cin >> n;

	nightSky.stars(n);
}
// PROIBIDO ALTERAR
int getAmountOfStars(const BlueSky& blueSky)
{
	return blueSky.stars();
}
// PROIBIDO ALTERAR
int main(int argc, char** argv)
{
	BlueNightSky blueNightSky;

	readInput(blueNightSky);

	std::cout << getAmountOfStars(blueNightSky) << std::endl;

	return 0;
}
