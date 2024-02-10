modded class Environment
{
	float	COLD_ZONE_TEMPERATURE_COEF = 0.5;	//higher value makes it colder
	float	COLD_ZONE_WETPENALTY_COEF = 0.2;	//higher value makes it colder
	vector	COLD_ZONE_CENTER = "1184 0 5400";
	float	COLD_ZONE_RADIUS = 10.0;
	
	bool IsInsideColdZone()
	{
		bool isInside = false;
		vector playerPos = m_Player.GetPosition();
		isInside = Math.IsPointInCircle(COLD_ZONE_CENTER, COLD_ZONE_RADIUS, playerPos);
		return isInside;
	}
	
	override protected float GetEnvironmentTemperature()
	{
		float temperature = super.GetEnvironmentTemperature();

		if (IsInsideColdZone())
		{
			float tempCalculation = temperature;
			
			if( tempCalculation < 5.0 && tempCalculation > -5.0)
			{
				tempCalculation = 5.0;
			}
			
			if (IsWaterContact())
			{
				temperature -= Math.AbsFloat(tempCalculation * COLD_ZONE_WETPENALTY_COEF);
			}
			
			temperature -= Math.AbsFloat(tempCalculation * COLD_ZONE_TEMPERATURE_COEF);
		}
		return temperature;
	}
};




	