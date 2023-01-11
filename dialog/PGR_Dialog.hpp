class PGR_Dialog {
	idd = -1;
	enableSimulation = true;
	
	class ControlsBackground {
		class TitleBar: ctrlStaticTitle {
			moving = true; //Toggles possibility to drag the dialog across the screen.
			colorBackground[] = {PGR_COL_HIGHLIGHT};
			colorText[] = {PGR_COL_TEXT_TITLE};
			font = "PuristaMedium";
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			shadow = 0;
			text = "Player Groups and Roles";
			x = 0;
			y = 0;
			w = 1;
			h = 0.04;
		};
		
		class Background: ctrlStaticBackground {
			colorBackground[] = {PGR_COL_BACKGROUND};
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.91;
		};
	};

	class Controls {
		class Filter: ctrlListNBox {
			idc = PGR_IDC_Filter;
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.04;
		};

		class Content: ctrlListNBox {
			idc = PGR_IDC_Content;
			disableOverflow = 1;
			tooltipPerColumn = 1;
			x = 0;
			y = 0.085;
			w = 1;
			h = 0.87;
		};

		class CloseButton: ctrlShortcutButton {
			onButtonClick = "closeDialog 0;";
			text = "CLOSE";
			x = 0.875;
			y = 0.96;
			w = 0.125;
			h = 0.04;
		};
	};
};
