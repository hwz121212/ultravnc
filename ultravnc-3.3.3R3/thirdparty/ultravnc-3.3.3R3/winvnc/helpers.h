#pragma once






void Real_stop_service();
void Set_stop_service_as_admin();
void Real_start_service();
void Set_start_service_as_admin();
void Real_settings(char *mycommand);
void Set_settings_as_admin(char *mycommand);
void Set_uninstall_service_as_admin();
void Set_install_service_as_admin();
void winvncSecurityEditorHelper_as_admin();
bool GetServiceName(TCHAR *pszAppPath, TCHAR *pszServiceName);
void Open_homepage();
void Open_forum();