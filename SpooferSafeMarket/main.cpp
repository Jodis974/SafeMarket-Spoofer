#include "console.h";
#include "spoofer.h";
bool IsRunningAsAdmin() {
	BOOL isAdmin = FALSE;
	PSID adminGroup = NULL;

	SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0, &adminGroup)) {
		return false;
	}

	if (!CheckTokenMembership(NULL, adminGroup, &isAdmin)) {
		isAdmin = FALSE;
	}

	FreeSid(adminGroup);
	return isAdmin == TRUE;
}
int main() {
    SetConsoleOutputCP(1252);

    SetConsoleTitleA("SafeMarket Spoofer"); 
    Header();
    if (!IsRunningAsAdmin()) {
        Error("Vous devez ex�cuter ce spoofeur en tant qu'administrateur !");
        Success("Appuyez sur n'importe quelle touche pour quitter...");
        system("pause > nul");
        return 0;
    }
    if (!GetCryptoReg().empty()) {
        Success("Votre MUID pr�c�dent : " + GetCryptoReg());
        SetCryptoReg();
        Success("Votre nouveau MUID : " + GetCryptoReg());
    }
    else {
        Error("�chec de la r�cup�ration du MUID !");
        Success("Appuyez sur n'importe quelle touche pour quitter...");
        system("pause > nul");
        return 0;
    }
    if (!GetHwidReg().empty()) {
        Success("Votre HWID pr�c�dent : " + GetHwidReg());
        SetHwidReg();
        Success("Votre nouveau HWID : " + GetHwidReg());
    }

    Success("Rafra�chissement du profil utilisateur...");
    refreshNTUserData();

    if (RefreshUserProfile()) {
        Success("Profil utilisateur rafra�chi avec succ�s !");
    }

    Success("Spoofing r�ussi !");
    Success("Appuyez sur n'importe quelle touche pour quitter...");
    system("pause > nul");
    return 0;
}
