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
        Error("Vous devez exécuter ce spoofeur en tant qu'administrateur !");
        Success("Appuyez sur n'importe quelle touche pour quitter...");
        system("pause > nul");
        return 0;
    }
    if (!GetCryptoReg().empty()) {
        Success("Votre MUID précédent : " + GetCryptoReg());
        SetCryptoReg();
        Success("Votre nouveau MUID : " + GetCryptoReg());
    }
    else {
        Error("Échec de la récupération du MUID !");
        Success("Appuyez sur n'importe quelle touche pour quitter...");
        system("pause > nul");
        return 0;
    }
    if (!GetHwidReg().empty()) {
        Success("Votre HWID précédent : " + GetHwidReg());
        SetHwidReg();
        Success("Votre nouveau HWID : " + GetHwidReg());
    }

    Success("Rafraîchissement du profil utilisateur...");
    refreshNTUserData();

    if (RefreshUserProfile()) {
        Success("Profil utilisateur rafraîchi avec succès !");
    }

    Success("Spoofing réussi !");
    Success("Appuyez sur n'importe quelle touche pour quitter...");
    system("pause > nul");
    return 0;
}
