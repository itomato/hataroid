#include "main.h"

#include "gui-android.h"

int DlgAlert_Notice(const char *text)
{
	Debug_Printf("Hatari DlgAlert_Notice: '%s'", text);
	showGenericDialog(0, text, 1, 0);
	for (;;)
	{
		if (hasDialogResult()==1)
		{
			break;
		}
		else
		{
			usleep(500000); // 0.5 sec
		}
	}
	clearDialogResult();
	return 0;
}

int DlgAlert_Query(const char *text)
{
	Debug_Printf("Hatari DlgAlert_Query: '%s'", text);
	showGenericDialog(0, text, 0 , 1);
	int res = 0;
	for (;;)
	{
		if (hasDialogResult()==1)
		{
			res = getDialogResult();
			break;
		}
		else
		{
			usleep(500000); // 0.5 sec
		}
	}
	clearDialogResult();
	return res;
}

// dummy functions for unused calls on Android
char* SDLGui_FileSelect(const char *path_and_name, char **zip_path, bool bAllowNew)
{
	return 0;
}

bool Dialog_DoProperty(void)
{
	Debug_Printf("Hatari Dialog_DoProperty");

	clearEmuCommands();
	clearSettingsResult();

	showOptionsDialog(0);

	for (;;)
	{
		//if (hasEmuCommands())
		if (hasSettingsResult())
		{
			break;
		}
		usleep(500000); // 0.5 sec
	}
	clearSettingsResult();

	while (hasEmuCommands())
	{
		processEmuCommands();
		usleep(50000);
	}

	return 0;
}

void Dialog_HaltDlg(void)
{
    // TODO
    hataroid_setDoubleBusError();
}