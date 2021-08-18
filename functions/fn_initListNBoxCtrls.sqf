/*
Description:
	Initializes and populates the PGR_Filter and PGR_Content controls when the PGR dialog is created.
Parameters:
	_parentDisplay: DISPLAY
*/

disableSerialization;

params ["_parentDisplay"];

private _filterCtrl = _parentDisplay displayCtrl 100;
private _contentCtrl = _parentDisplay displayCtrl 101;

private _addWeightCol = !isNil "ace_common_fnc_getWeight";

//Add columns (the first one already exists):
if (_addWeightCol) then {
	{
		_x lnbAddColumn 0.3;
		_x lnbAddColumn 0.6;
		_x lnbAddColumn 0.9;
	} forEach [_filterCtrl, _contentCtrl];
} else {
	{
		_x lnbAddColumn 0.33;
		_x lnbAddColumn 0.66;
	} forEach [_filterCtrl, _contentCtrl];
};

//Add column headers:
_filterCtrl lnbAddRow ["Name", "Group", "Role"];

if (_addWeightCol) then {
	_filterCtrl lnbSetText [[0, 3], "Weight"];
};

//Add rows with player information:
{
	_contentCtrl lnbAddRow [name _x, groupId group _x, (roleDescription _x splitString "@") # 0]; //splitString to deal with https://github.com/CBATeam/CBA_A3/wiki/Name-Groups-in-Lobby.
	_contentCtrl lnbSetPicture [[_forEachIndex, 0], getText (configFile >> "CfgRanks" >> str rankId _x >> "texture")];
	_contentCtrl lnbSetPicture [[_forEachIndex, 1], [side group _x] call PGR_fnc_getSidePicture];
	_contentCtrl lnbSetPictureColor [[_forEachIndex, 1], [side group _x] call BIS_fnc_sideColor];
	
	if (_addWeightCol) then {
		_contentCtrl lnbSetTextRight [[_forEachIndex, 3], [_x, systemOfUnits == 2] call ace_common_fnc_getWeight]; //lnbSetTextRight is currently broken (the text is not rendered).
		_contentCtrl lnbSetText [[_forEachIndex, 3], [_x, systemOfUnits == 2] call ace_common_fnc_getWeight]; //Can probably use this for sorting (unless it leads to visual glitches).
		//_contentCtrl lnbSetColor [[_forEachIndex, 3], [1, 1, 1, 0]];
	};
} forEach allUnits; //(allPlayers select {!(_x isKindOf "VirtualMan_F")}); //The select-statement removes Headless Clients, Virtual Spectators and Virtual Curators.

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

ctrlSetFocus _contentCtrl;