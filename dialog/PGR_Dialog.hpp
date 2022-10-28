#define GUI_BACKGROUND_COLOR {"(profileNamespace getVariable ['GUI_BCG_RGB_R', 0.13])", "(profileNamespace getVariable ['GUI_BCG_RGB_G', 0.54])", "(profileNamespace getVariable ['GUI_BCG_RGB_B', 0.21])", "(profileNamespace getVariable ['GUI_BCG_RGB_A', 0.8])"}

class PGR_Dialog {
	idd = -1;
	enableSimulation = true;
	onLoad = "_this call PGR_fnc_initListNBoxCtrls;";
	
	class ControlsBackground {
		class PGR_DialogTitleBar {
			idc = -1;
			moving = true; //Toggles possibility to drag the dialog across the screen.
			type = CT_STATIC;
			style = ST_LEFT;
			shadow = 0;
			colorBackground[] = GUI_BACKGROUND_COLOR;
			colorText[] = {1, 1, 1, 1};
			font = "PuristaMedium";
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			text = "Player Groups and Roles";
			x = 0;
			y = 0;
			w = 1;
			h = 0.04;
		};
		
		class PGR_DialogBackground {
			idc = -1;
			type = CT_STATIC;
			style = ST_CENTER;
			shadow = 0;
			colorBackground[] = {0, 0, 0, 0.6};
			colorText[] = {1, 1, 1, 1};
			font = "RobotoCondensed";
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			text = "";
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.91;
		};
	};

	class Controls {
		class PGR_Filter: ctrlListNBox {
			idc = 100;
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.04;
		};

		class PGR_Content: ctrlListNBox {
			idc = 101;
			disableOverflow = 1;
			tooltipPerColumn = 1;
			x = 0;
			y = 0.085;
			w = 1;
			h = 0.87;
		};

		class PGR_DialogButtonClose: ctrlShortcutButton {
			idc = -1;
			onButtonClick = "closeDialog 0;";
			text = "CLOSE";
			x = 0.875;
			y = 0.96;
			w = 0.125;
			h = 0.04;
		};
	};
};
