class CfgPatches
{
    class azw_ColdZone
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]={};
    };
};

class CfgMods
{
	class azw_ColdZone
	{
		dir = "azw_ColdZone";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "azw_ColdZone";
		credits = "AndreZ";
		author = "AndreZ";
		authorID = "0"; 
		version = "0.1"; 
		extra = 0;
		type = "mod";
		
		dependencies[] = {"World"};
		
		class defs
		{

			class worldScriptModule
			{
				value = "";
				files[] = {"azw_ColdZone/Scripts/4_World"};
			};
		};
	};
};