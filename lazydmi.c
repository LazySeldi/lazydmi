/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This file is part of lazybios.
 *
 * lazydmi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * lazydmi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lazybios. If not, see <https://www.gnu.org/licenses/>.
 */
#define LAZYDMI_VER "1.1.0"
#define LAZYDMI_MAJOR 1
#define LAZYDMI_MINOR 1
#define LAZYDMI_PATCH 0

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lazybios.h"

typedef struct {
    const char *name;
    int number;
} type_alias_t;


// This list was 100% AI generated, I'm not typing all of that lol
static const type_alias_t type_aliases[] = {
    // Type 0
    {"bios", 0},
    {"biosinfo", 0},
    {"biosinformation", 0},
    {"firmwarebios", 0},
    {"systembios", 0},
    {"platformbios", 0},
    {"rombios", 0},
    {"biosrom", 0},
    {"biosversion", 0},
    {"biosvendor", 0},
    {"biosdetails", 0},
    {"firmwareinfo", 0},
    {"platformfirmware", 0},
    {"type0", 0},
    {"smbiostype0", 0},
    {"dmitype0", 0},
    {"dmi0", 0},

    // Type 1
    {"system", 1},
    {"sysinfo", 1},
    {"product", 1},
    {"systeminfo", 1},
    {"systeminformation", 1},
    {"systemproduct", 1},
    {"systemproductinfo", 1},
    {"computer", 1},
    {"computerinfo", 1},
    {"machine", 1},
    {"machineinfo", 1},
    {"platform", 1},
    {"platforminfo", 1},
    {"productinfo", 1},
    {"systemidentity", 1},
    {"systemuuid", 1},
    {"systemserial", 1},
    {"type1", 1},
    {"smbiostype1", 1},
    {"dmitype1", 1},
    {"dmi1", 1},

    // Type 2
    {"baseboard", 2},
    {"board", 2},
    {"motherboard", 2},
    {"mainboard", 2},
    {"systemboard", 2},
    {"logicboard", 2},
    {"baseboardinfo", 2},
    {"boardinfo", 2},
    {"motherboardinfo", 2},
    {"mainboardinfo", 2},
    {"systemboardinfo", 2},
    {"boardproduct", 2},
    {"boardserial", 2},
    {"boardvendor", 2},
    {"mb", 2},
    {"mobo", 2},
    {"type2", 2},
    {"smbiostype2", 2},
    {"dmitype2", 2},
    {"dmi2", 2},

    // Type 3
    {"chassis", 3},
    {"enclosure", 3},
    {"case", 3},
    {"systemcase", 3},
    {"computerchassis", 3},
    {"systemchassis", 3},
    {"chassisinfo", 3},
    {"enclosureinfo", 3},
    {"caseinfo", 3},
    {"chassistype", 3},
    {"enclosuretype", 3},
    {"chassisserial", 3},
    {"caseserial", 3},
    {"cabinet", 3},
    {"housing", 3},
    {"type3", 3},
    {"smbiostype3", 3},
    {"dmitype3", 3},
    {"dmi3", 3},

    // Type 4
    {"processor", 4},
    {"cpu", 4},
    {"proc", 4},
    {"processorinfo", 4},
    {"cpuinfo", 4},
    {"centralprocessor", 4},
    {"centralprocessingunit", 4},
    {"socket", 4},
    {"cpusocket", 4},
    {"processorsocket", 4},
    {"processorversion", 4},
    {"cpumodel", 4},
    {"processorname", 4},
    {"cpuclock", 4},
    {"cpufamily", 4},
    {"cpucores", 4},
    {"processordetails", 4},
    {"type4", 4},
    {"smbiostype4", 4},
    {"dmitype4", 4},
    {"dmi4", 4},

    // Type 5 - obsolete
    {"memctrl", 5},
    {"memorycontroller", 5},
    {"memoryctrl", 5},
    {"memcontroller", 5},
    {"memorycontrollerinfo", 5},
    {"memorycontrol", 5},
    {"ramcontroller", 5},
    {"dramcontroller", 5},
    {"memorycontrollerobsolete", 5},
    {"legacymemorycontroller", 5},
    {"oldmemorycontroller", 5},
    {"type5", 5},
    {"smbiostype5", 5},
    {"dmitype5", 5},
    {"dmi5", 5},

    // Type 6 - obsolete
    {"memmodule", 6},
    {"memorymodule", 6},
    {"memorymoduleinfo", 6},
    {"modulememory", 6},
    {"rammodule", 6},
    {"dimmodule", 6},
    {"simmodule", 6},
    {"memorymoduleobsolete", 6},
    {"legacymemorymodule", 6},
    {"oldmemorymodule", 6},
    {"moduleinfo", 6},
    {"type6", 6},
    {"smbiostype6", 6},
    {"dmitype6", 6},
    {"dmi6", 6},

    // Type 7
    {"cache", 7},
    {"cachemem", 7},
    {"l2cache", 7},
    {"l3cache", 7},
    {"l1cache", 7},
    {"cacheinfo", 7},
    {"cacheinformation", 7},
    {"cachememory", 7},
    {"processorcache", 7},
    {"cpucache", 7},
    {"internalcache", 7},
    {"externalcache", 7},
    {"level1cache", 7},
    {"level2cache", 7},
    {"level3cache", 7},
    {"cachelevel", 7},
    {"cachesize", 7},
    {"cacheconfig", 7},
    {"type7", 7},
    {"smbiostype7", 7},
    {"dmitype7", 7},
    {"dmi7", 7},

    // Type 8
    {"port", 8},
    {"connector", 8},
    {"portconnector", 8},
    {"portinfo", 8},
    {"connectorinfo", 8},
    {"portconnectorinfo", 8},
    {"internalconnector", 8},
    {"externalconnector", 8},
    {"ioport", 8},
    {"ioports", 8},
    {"physicalport", 8},
    {"systemport", 8},
    {"rearport", 8},
    {"frontport", 8},
    {"portconnection", 8},
    {"porttype", 8},
    {"connectortype", 8},
    {"type8", 8},
    {"smbiostype8", 8},
    {"dmitype8", 8},
    {"dmi8", 8},

    // Type 9
    {"slot", 9},
    {"slots", 9},
    {"pci", 9},
    {"pcislot", 9},
    {"pcie", 9},
    {"pcieslot", 9},
    {"systemslot", 9},
    {"systemslots", 9},
    {"expansionslot", 9},
    {"expansionslots", 9},
    {"slotinfo", 9},
    {"slotinformation", 9},
    {"pciexpress", 9},
    {"pciexpressslot", 9},
    {"agpslot", 9},
    {"isaslot", 9},
    {"eisaslot", 9},
    {"m2slot", 9},
    {"m2", 9},
    {"slotdesignation", 9},
    {"type9", 9},
    {"smbiostype9", 9},
    {"dmitype9", 9},
    {"dmi9", 9},

    // Type 10
    {"onboard", 10},
    {"onboarddev", 10},
    {"device", 10},
    {"onboarddevice", 10},
    {"onboarddevices", 10},
    {"onboarddeviceinfo", 10},
    {"builtin", 10},
    {"builtindevice", 10},
    {"integrateddevice", 10},
    {"embeddeddevice", 10},
    {"boarddevice", 10},
    {"motherboarddevice", 10},
    {"onboardhardware", 10},
    {"integratedhardware", 10},
    {"onboardlegacy", 10},
    {"type10", 10},
    {"smbiostype10", 10},
    {"dmitype10", 10},
    {"dmi10", 10},

    // Type 11
    {"oem", 11},
    {"oemstrings", 11},
    {"vendor", 11},
    {"oemstring", 11},
    {"oeminfo", 11},
    {"oeminformation", 11},
    {"vendorstrings", 11},
    {"vendorstring", 11},
    {"manufacturerstrings", 11},
    {"manufacturerstring", 11},
    {"customstrings", 11},
    {"customstring", 11},
    {"systemstrings", 11},
    {"platformstrings", 11},
    {"oemdata", 11},
    {"vendordata", 11},
    {"type11", 11},
    {"smbiostype11", 11},
    {"dmitype11", 11},
    {"dmi11", 11},

    // Type 12
    {"config", 12},
    {"sysconfig", 12},
    {"options", 12},
    {"configuration", 12},
    {"systemconfig", 12},
    {"systemconfiguration", 12},
    {"systemoptions", 12},
    {"configoptions", 12},
    {"configurationoptions", 12},
    {"systemconfigoptions", 12},
    {"systemconfigurationoptions", 12},
    {"configstrings", 12},
    {"optionstrings", 12},
    {"bootoptions", 12},
    {"platformoptions", 12},
    {"type12", 12},
    {"smbiostype12", 12},
    {"dmitype12", 12},
    {"dmi12", 12},

    // Type 13
    {"bioslang", 13},
    {"bioslanguage", 13},
    {"language", 13},
    {"bioslanguages", 13},
    {"languages", 13},
    {"languageinfo", 13},
    {"bioslanguageinfo", 13},
    {"bioslanguageinformation", 13},
    {"firmwarelanguage", 13},
    {"firmwarelanguages", 13},
    {"supportedlanguages", 13},
    {"currentlanguage", 13},
    {"systemlanguage", 13},
    {"platformlanguage", 13},
    {"localization", 13},
    {"locale", 13},
    {"type13", 13},
    {"smbiostype13", 13},
    {"dmitype13", 13},
    {"dmi13", 13},

    // Type 14
    {"group", 14},
    {"groups", 14},
    {"assoc", 14},
    {"association", 14},
    {"associations", 14},
    {"groupassociation", 14},
    {"groupassociations", 14},
    {"groupinfo", 14},
    {"groupinformation", 14},
    {"associatedgroup", 14},
    {"structuregroup", 14},
    {"structureassociation", 14},
    {"structureassociations", 14},
    {"linkedstructures", 14},
    {"relatedstructures", 14},
    {"type14", 14},
    {"smbiostype14", 14},
    {"dmitype14", 14},
    {"dmi14", 14},

    // Type 15
    {"eventlog", 15},
    {"syslog", 15},
    {"elog", 15},
    {"systemeventlog", 15},
    {"systemlog", 15},
    {"eventlogger", 15},
    {"eventlogging", 15},
    {"eventloginfo", 15},
    {"eventloginformation", 15},
    {"hardwarelog", 15},
    {"firmwarelog", 15},
    {"bioslog", 15},
    {"errorlog", 15},
    {"systemevents", 15},
    {"platformeventlog", 15},
    {"sel", 15},
    {"type15", 15},
    {"smbiostype15", 15},
    {"dmitype15", 15},
    {"dmi15", 15},

    // Type 16
    {"memoryarr", 16},
    {"memarray", 16},
    {"memoryarray", 16},
    {"physicalmemory", 16},
    {"ramarray", 16},
    {"physicalmemoryarray", 16},
    {"physicalram", 16},
    {"systemmemory", 16},
    {"memoryarrayinfo", 16},
    {"memoryarrayinformation", 16},
    {"ramarrayinfo", 16},
    {"memorycapacity", 16},
    {"maximumcapacity", 16},
    {"maxmemory", 16},
    {"maxram", 16},
    {"memorybankarray", 16},
    {"dimmarray", 16},
    {"memoryslotsummary", 16},
    {"memorysummary", 16},
    {"type16", 16},
    {"smbiostype16", 16},
    {"dmitype16", 16},
    {"dmi16", 16},

    // Type 17
       {"memory",  17},
    {"memdev", 17},
       {"memdevice", 17},
    {"memorydevice", 17},
    {"dimm", 17},
    {"ram", 17},
    {"memorydevices", 17},
    {"memorydeviceinfo", 17},
    {"memorydeviceinformation", 17},
    {"ramdevice", 17},
    {"dimmdevice", 17},
    {"memorymoduledevice", 17},
    {"physicalmemorydevice", 17},
    {"memoryslot", 17},
    {"ramslot", 17},
    {"dimmslot", 17},
    {"memorybank", 17},
    {"rambank", 17},
    {"installedmemory", 17},
    {"installedram", 17},
    {"memorymoduleinfo", 17},
    {"raminfo", 17},
    {"dimminfo", 17},
    {"memoryspeed", 17},
    {"ramstick", 17},
    {"memorystick", 17},
    {"type17", 17},
    {"smbiostype17", 17},
    {"dmitype17", 17},
    {"dmi17", 17},

    // Type 18
    {"memerror32", 18},
    {"memoryerror32", 18},
    {"error32", 18},
    {"memoryerror", 18},
    {"memoryerrorinfo32", 18},
    {"memoryerrorinformation32", 18},
    {"memoryerrorinformation", 18},
    {"memoryfault32", 18},
    {"ramerror32", 18},
    {"ramfault32", 18},
    {"eccerror32", 18},
    {"memoryecc32", 18},
    {"legacymemoryerror", 18},
    {"bit32memoryerror", 18},
    {"32bitmemoryerror", 18},
    {"type18", 18},
    {"smbiostype18", 18},
    {"dmitype18", 18},
    {"dmi18", 18},

    // Type 19
    {"memmap", 19},
    {"memorymap", 19},
    {"arrayaddr", 19},
    {"memoryarraymap", 19},
    {"memoryarraymapped", 19},
    {"memoryarrayaddress", 19},
    {"memoryarraymappedaddress", 19},
    {"physicalmemorymap", 19},
    {"physicalmemoryaddress", 19},
    {"rammap", 19},
    {"ramaddressmap", 19},
    {"memoryaddressrange", 19},
    {"arrayaddressrange", 19},
    {"mappedmemoryarray", 19},
    {"mappedmemoryrange", 19},
    {"memoryrange", 19},
    {"type19", 19},
    {"smbiostype19", 19},
    {"dmitype19", 19},
    {"dmi19", 19},

    // Type 20
    {"memdevmap", 20},
    {"memorydevmap", 20},
    {"devaddr", 20},
    {"memorydevicemapped", 20},
    {"memorydevicemappedaddress", 20},
    {"memorydeviceaddress", 20},
    {"memorydevicerange", 20},
    {"ramdevicemap", 20},
    {"ramdeviceaddress", 20},
    {"dimmmap", 20},
    {"dimmaddress", 20},
    {"mappedmemorydevice", 20},
    {"mappedramdevice", 20},
    {"devicememorymap", 20},
    {"deviceaddressrange", 20},
    {"memorymapping", 20},
    {"type20", 20},
    {"smbiostype20", 20},
    {"dmitype20", 20},
    {"dmi20", 20},

    // Type 21
    {"pointer", 21},
    {"pointing", 21},
    {"mouse", 21},
    {"touchpad", 21},
    {"pointingdevice", 21},
    {"builtinpointingdevice", 21},
    {"internalpointingdevice", 21},
    {"trackpad", 21},
    {"trackball", 21},
    {"digitizer", 21},
    {"pointingdeviceinfo", 21},
    {"mouseinfo", 21},
    {"touchpadinfo", 21},
    {"integratedmouse", 21},
    {"builtinmouse", 21},
    {"builtintouchpad", 21},
    {"cursorcontrol", 21},
    {"type21", 21},
    {"smbiostype21", 21},
    {"dmitype21", 21},
    {"dmi21", 21},

    // Type 22
    {"battery", 22},
    {"bat", 22},
    {"portablebat", 22},
    {"portablebattery", 22},
    {"systembattery", 22},
    {"laptopbattery", 22},
    {"notebookbattery", 22},
    {"internalbattery", 22},
    {"mainbattery", 22},
    {"batteryinfo", 22},
    {"batteryinformation", 22},
    {"batterydevice", 22},
    {"batterycapacity", 22},
    {"batterystatus", 22},
    {"batteryserial", 22},
    {"batterychemistry", 22},
    {"batteryvoltage", 22},
    {"type22", 22},
    {"smbiostype22", 22},
    {"dmitype22", 22},
    {"dmi22", 22},

    // Type 23
    {"reset", 23},
    {"sysreset", 23},
    {"systemreset", 23},
    {"resetinfo", 23},
    {"resetinformation", 23},
    {"systemresetinfo", 23},
    {"systemresetinformation", 23},
    {"resetcontrol", 23},
    {"resetstatus", 23},
    {"resetcount", 23},
    {"resetlimit", 23},
    {"watchdogreset", 23},
    {"hardwarereset", 23},
    {"bootreset", 23},
    {"automaticreset", 23},
    {"type23", 23},
    {"smbiostype23", 23},
    {"dmitype23", 23},
    {"dmi23", 23},

    // Type 24
    {"security", 24},
    {"hardwaresec", 24},
    {"hwsecurity", 24},
    {"hardwaresecurity", 24},
    {"securityinfo", 24},
    {"securityinformation", 24},
    {"hardwaresecurityinfo", 24},
    {"systemsecurity", 24},
    {"passwordsecurity", 24},
    {"biossecurity", 24},
    {"adminpassword", 24},
    {"administratorpassword", 24},
    {"userpassword", 24},
    {"keyboardpassword", 24},
    {"frontpanelreset", 24},
    {"securitysettings", 24},
    {"type24", 24},
    {"smbiostype24", 24},
    {"dmitype24", 24},
    {"dmi24", 24},

    // Type 25
    {"powerctrl", 25},
    {"powercontrol", 25},
    {"syspower", 25},
    {"systempowercontrol", 25},
    {"systempowercontrols", 25},
    {"powercontrols", 25},
    {"powercontrolinfo", 25},
    {"powercontrolinformation", 25},
    {"scheduledpower", 25},
    {"poweroncontrol", 25},
    {"poweronschedule", 25},
    {"wakeupschedule", 25},
    {"systemwake", 25},
    {"wakecontrol", 25},
    {"powercyclecontrol", 25},
    {"type25", 25},
    {"smbiostype25", 25},
    {"dmitype25", 25},
    {"dmi25", 25},

    // Type 26
    {"voltage", 26},
    {"vprobe", 26},
    {"voltageprobe", 26},
    {"volt", 26},
    {"volts", 26},
    {"voltagesensor", 26},
    {"voltagesensors", 26},
    {"voltageinfo", 26},
    {"voltageinformation", 26},
    {"voltagemonitor", 26},
    {"voltmonitor", 26},
    {"voltagereading", 26},
    {"voltagestatus", 26},
    {"voltageprobeinfo", 26},
    {"systemvoltage", 26},
    {"railvoltage", 26},
    {"vcore", 26},
    {"type26", 26},
    {"smbiostype26", 26},
    {"dmitype26", 26},
    {"dmi26", 26},

    // Type 27
    {"cooling", 27},
    {"cool", 27},
    {"fan", 27},
    {"fans", 27},
    {"coolingdevice", 27},
    {"coolingdevices", 27},
    {"coolinginfo", 27},
    {"coolinginformation", 27},
    {"faninfo", 27},
    {"faninformation", 27},
    {"systemfan", 27},
    {"cpufan", 27},
    {"chassisfan", 27},
    {"casefan", 27},
    {"powerfan", 27},
    {"blower", 27},
    {"cooler", 27},
    {"coolingsystem", 27},
    {"fanspeed", 27},
    {"fanrpm", 27},
    {"rpm", 27},
    {"type27", 27},
    {"smbiostype27", 27},
    {"dmitype27", 27},
    {"dmi27", 27},

    // Type 28
    {"temp", 28},
    {"temperature", 28},
    {"tprobe", 28},
    {"temperatureprobe", 28},
    {"tempsensor", 28},
    {"temperaturesensor", 28},
    {"thermalsensor", 28},
    {"thermal", 28},
    {"thermalprobe", 28},
    {"tempinfo", 28},
    {"temperatureinfo", 28},
    {"temperatureinformation", 28},
    {"tempmonitor", 28},
    {"temperaturemonitor", 28},
    {"thermalmonitor", 28},
    {"systemtemperature", 28},
    {"cputemperature", 28},
    {"boardtemperature", 28},
    {"chassistemperature", 28},
    {"ambienttemperature", 28},
    {"type28", 28},
    {"smbiostype28", 28},
    {"dmitype28", 28},
    {"dmi28", 28},

    // Type 29
    {"current", 29},
    {"iprobe", 29},
    {"currentprobe", 29},
    {"electricalcurrent", 29},
    {"electricalcurrentprobe", 29},
    {"currentsensor", 29},
    {"ampsensor", 29},
    {"ampereprobe", 29},
    {"amperage", 29},
    {"amps", 29},
    {"currentinfo", 29},
    {"currentinformation", 29},
    {"currentmonitor", 29},
    {"amperagemonitor", 29},
    {"currentreading", 29},
    {"powercurrent", 29},
    {"systemcurrent", 29},
    {"type29", 29},
    {"smbiostype29", 29},
    {"dmitype29", 29},
    {"dmi29", 29},

    // Type 30
    {"remote", 30},
    {"oob", 30},
    {"outofband", 30},
    {"bmc", 30},
    {"remoteaccess", 30},
    {"outofbandremoteaccess", 30},
    {"remoteaccessinfo", 30},
    {"remoteaccessinformation", 30},
    {"oobaccess", 30},
    {"oobmanagement", 30},
    {"remoteconsole", 30},
    {"managementaccess", 30},
    {"remotemanagement", 30},
    {"bmcaccess", 30},
    {"bmcremote", 30},
    {"remotecontrol", 30},
    {"systemremoteaccess", 30},
    {"type30", 30},
    {"smbiostype30", 30},
    {"dmitype30", 30},
    {"dmi30", 30},

    // Type 31
    {"bis", 31},
    {"bootintegrity", 31},
    {"integrity", 31},
    {"bisentry", 31},
    {"bisentrypoint", 31},
    {"bootintegrityservice", 31},
    {"bootintegrityservices", 31},
    {"bootintegrityentry", 31},
    {"bootintegrityentrypoint", 31},
    {"integrityservice", 31},
    {"integrityservices", 31},
    {"securebootintegrity", 31},
    {"firmwareintegrity", 31},
    {"legacybis", 31},
    {"type31", 31},
    {"smbiostype31", 31},
    {"dmitype31", 31},
    {"dmi31", 31},

    // Type 32
    {"boot", 32},
    {"sysboot", 32},
    {"bootinfo", 32},
    {"systemboot", 32},
    {"systembootinfo", 32},
    {"systembootinformation", 32},
    {"bootinformation", 32},
    {"bootstatus", 32},
    {"systembootstatus", 32},
    {"bootresult", 32},
    {"bootstate", 32},
    {"booterror", 32},
    {"bootfailure", 32},
    {"bootdiagnostic", 32},
    {"bootdiagnostics", 32},
    {"bootrecord", 32},
    {"bootdata", 32},
    {"type32", 32},
    {"smbiostype32", 32},
    {"dmitype32", 32},
    {"dmi32", 32},

    // Type 33
    {"memerror64", 33},
    {"memoryerror64", 33},
    {"error64", 33},
    {"memoryerrorinfo64", 33},
    {"memoryerrorinformation64", 33},
    {"memoryfault64", 33},
    {"ramerror64", 33},
    {"ramfault64", 33},
    {"eccerror64", 33},
    {"memoryecc64", 33},
    {"extendedmemoryerror", 33},
    {"bit64memoryerror", 33},
    {"64bitmemoryerror", 33},
    {"extendedramerror", 33},
    {"physicalmemoryerror64", 33},
    {"type33", 33},
    {"smbiostype33", 33},
    {"dmitype33", 33},
    {"dmi33", 33},

    // Type 34
    {"mgmtdev", 34},
    {"managementdev", 34},
    {"mgtdev", 34},
    {"managementdevice", 34},
    {"managementdeviceinfo", 34},
    {"managementdeviceinformation", 34},
    {"mgmtdevice", 34},
    {"mgtdevice", 34},
    {"hardwaremanagementdevice", 34},
    {"systemmanagementdevice", 34},
    {"monitoringdevice", 34},
    {"managementsensor", 34},
    {"managementhardware", 34},
    {"managementcontrollerdevice", 34},
    {"managementinterface", 34},
    {"type34", 34},
    {"smbiostype34", 34},
    {"dmitype34", 34},
    {"dmi34", 34},

    // Type 35
    {"mgmtcomp", 35},
    {"managementcomp", 35},
    {"mgtcomp", 35},
    {"managementcomponent", 35},
    {"managementdevicecomponent", 35},
    {"managementcomponentinfo", 35},
    {"managementcomponentinformation", 35},
    {"mgmtcomponent", 35},
    {"mgtcomponent", 35},
    {"devicecomponent", 35},
    {"managedcomponent", 35},
    {"managementdevcomponent", 35},
    {"monitoringcomponent", 35},
    {"hardwaremanagementcomponent", 35},
    {"systemmanagementcomponent", 35},
    {"type35", 35},
    {"smbiostype35", 35},
    {"dmitype35", 35},
    {"dmi35", 35},

    // Type 36
    {"mgmtthreshold", 36},
    {"threshold", 36},
    {"mgtthreshold", 36},
    {"managementthreshold", 36},
    {"managementthresholds", 36},
    {"managementdevicethreshold", 36},
    {"managementdevicethresholds", 36},
    {"managementthresholddata", 36},
    {"thresholddata", 36},
    {"thresholdinfo", 36},
    {"thresholdinformation", 36},
    {"sensorthreshold", 36},
    {"sensorthresholds", 36},
    {"warningthreshold", 36},
    {"criticalthreshold", 36},
    {"monitoringthreshold", 36},
    {"alarmthreshold", 36},
    {"type36", 36},
    {"smbiostype36", 36},
    {"dmitype36", 36},
    {"dmi36", 36},

    // Type 37
    {"memchannel", 37},
    {"channel", 37},
    {"memorychannel", 37},
    {"memorychannels", 37},
    {"ramchannel", 37},
    {"ramchannels", 37},
    {"dimmchannel", 37},
    {"memorychannelinfo", 37},
    {"memorychannelinformation", 37},
    {"channelinfo", 37},
    {"channelinformation", 37},
    {"memorychanneldevice", 37},
    {"memorychanneldevices", 37},
    {"ramchannelinfo", 37},
    {"multichannelmemory", 37},
    {"dualchannel", 37},
    {"triplechannel", 37},
    {"quadchannel", 37},
    {"type37", 37},
    {"smbiostype37", 37},
    {"dmitype37", 37},
    {"dmi37", 37},

    // Type 38
    {"ipmi", 38},
    {"ipmidev", 38},
    {"ipmidevice", 38},
    {"ipmiinfo", 38},
    {"ipmiinformation", 38},
    {"ipmideviceinfo", 38},
    {"ipmideviceinformation", 38},
    {"ipmiinterface", 38},
    {"ipmiconfiguration", 38},
    {"ipmiconfig", 38},
    {"ipmicontroller", 38},
    {"ipmibmc", 38},
    {"baseboardmanagementcontroller", 38},
    {"bmcinterface", 38},
    {"bmcipmi", 38},
    {"managementinterfaceipmi", 38},
    {"intelligentplatformmanagement", 38},
    {"type38", 38},
    {"smbiostype38", 38},
    {"dmitype38", 38},
    {"dmi38", 38},

    // Type 39
    {"psu", 39},
    {"powersupply", 39},
    {"supply", 39},
    {"systempowersupply", 39},
    {"powersupplyinfo", 39},
    {"powersupplyinformation", 39},
    {"psuinfo", 39},
    {"psuinformation", 39},
    {"powerunit", 39},
    {"powerbrick", 39},
    {"poweradapter", 39},
    {"acadapter", 39},
    {"internalpsu", 39},
    {"systempsu", 39},
    {"powerwatts", 39},
    {"psuwattage", 39},
    {"powercapacity", 39},
    {"powersupplystatus", 39},
    {"redundantpsu", 39},
    {"type39", 39},
    {"smbiostype39", 39},
    {"dmitype39", 39},
    {"dmi39", 39},

    // Type 40
    {"additional", 40},
    {"addinfo", 40},
    {"extra", 40},
    {"additionalinfo", 40},
    {"additionalinformation", 40},
    {"extrainfo", 40},
    {"extrainformation", 40},
    {"supplemental", 40},
    {"supplementalinfo", 40},
    {"supplementalinformation", 40},
    {"extendedinfo", 40},
    {"extendedinformation", 40},
    {"custominfo", 40},
    {"custominformation", 40},
    {"platformadditionalinfo", 40},
    {"structureadditionalinfo", 40},
    {"miscinfo", 40},
    {"miscellaneousinfo", 40},
    {"type40", 40},
    {"smbiostype40", 40},
    {"dmitype40", 40},
    {"dmi40", 40},

    // Type 41
    {"onboardext", 41},
    {"onboardextended", 41},
    {"extdevice", 41},
    {"extendedonboard", 41},
    {"extendedonboarddevice", 41},
    {"onboarddeviceextended", 41},
    {"onboarddeviceextendedinfo", 41},
    {"onboarddeviceextendedinformation", 41},
    {"onboardextendedinfo", 41},
    {"onboardextendedinformation", 41},
    {"extendeddevice", 41},
    {"extendeddeviceinfo", 41},
    {"integrateddeviceextended", 41},
    {"builtinextendeddevice", 41},
    {"onboarddevicesextended", 41},
    {"onboarddeviceext", 41},
    {"extendedonboarddevices", 41},
    {"type41", 41},
    {"smbiostype41", 41},
    {"dmitype41", 41},
    {"dmi41", 41},

    // Type 42
    {"mgtcontroller", 42},
    {"mgmthost", 42},
    {"redfish", 42},
    {"hostinterface", 42},
    {"managementcontroller", 42},
    {"managementcontrollerhost", 42},
    {"managementcontrollerhostinterface", 42},
    {"managementhostinterface", 42},
    {"mchostinterface", 42},
    {"controllerhostinterface", 42},
    {"bmchostinterface", 42},
    {"bmchost", 42},
    {"bmcnetwork", 42},
    {"redfishinterface", 42},
    {"redfishhostinterface", 42},
    {"redfishoverip", 42},
    {"redfishnetwork", 42},
    {"managementnetworkinterface", 42},
    {"hostmanagementinterface", 42},
    {"outofbandinterface", 42},
    {"type42", 42},
    {"smbiostype42", 42},
    {"dmitype42", 42},
    {"dmi42", 42},

    // Type 43
    {"tpm", 43},
    {"trustedplatform", 43},
    {"securitychip", 43},
    {"tpmdevice", 43},
    {"tpminfo", 43},
    {"tpminformation", 43},
    {"tpmdeviceinfo", 43},
    {"tpmdeviceinformation", 43},
    {"trustedplatformmodule", 43},
    {"trustedplatformmoduledevice", 43},
    {"trustedmodule", 43},
    {"platformsecuritymodule", 43},
    {"trustedchip", 43},
    {"securitymodule", 43},
    {"hardwaretpm", 43},
    {"firmwaretpm", 43},
    {"ftpm", 43},
    {"discretetpm", 43},
    {"dtpm", 43},
    {"tpmversion", 43},
    {"tpmvendor", 43},
    {"type43", 43},
    {"smbiostype43", 43},
    {"dmitype43", 43},
    {"dmi43", 43},

    // Type 44
    {"procadditional", 44},
    {"procext", 44},
    {"cpuext", 44},
    {"processoradditional", 44},
    {"processoradditionalinfo", 44},
    {"processoradditionalinformation", 44},
    {"cpuadditional", 44},
    {"cpuadditionalinfo", 44},
    {"cpuadditionalinformation", 44},
    {"processorextended", 44},
    {"processorextendedinfo", 44},
    {"processorextendedinformation", 44},
    {"cpuextended", 44},
    {"cpuextendedinfo", 44},
    {"processorarchitectureinfo", 44},
    {"processorcharacteristics", 44},
    {"processorblock", 44},
    {"processorrawdata", 44},
    {"type44", 44},
    {"smbiostype44", 44},
    {"dmitype44", 44},
    {"dmi44", 44},

    // Type 45
    {"firmware", 45},
    {"fw", 45},
    {"fwinv", 45},
    {"fwinventory", 45},
    {"firmwareinventory", 45},
    {"firmwareinventoryinfo", 45},
    {"firmwareinventoryinformation", 45},
    {"firmwareinfo45", 45},
    {"firmwarecomponent", 45},
    {"firmwarecomponents", 45},
    {"firmwareimage", 45},
    {"firmwareimages", 45},
    {"firmwaredevice", 45},
    {"firmwareversion", 45},
    {"firmwareversions", 45},
    {"componentfirmware", 45},
    {"devicefirmware", 45},
    {"systemfirmwareinventory", 45},
    {"platformfirmwareinventory", 45},
    {"updateablefirmware", 45},
    {"updatablefirmware", 45},
    {"type45", 45},
    {"smbiostype45", 45},
    {"dmitype45", 45},
    {"dmi45", 45},

    // Type 46
    {"inactive", 46},
    {"reserved", 46},
    {"unused", 46},
    {"stringproperty", 46},
    {"stringproperties", 46},
    {"propertystring", 46},
    {"propertystrings", 46},
    {"stringpropertyinfo", 46},
    {"stringpropertyinformation", 46},
    {"smbiosstringproperty", 46},
    {"structurestringproperty", 46},
    {"structureproperty", 46},
    {"structureproperties", 46},
    {"referencedstring", 46},
    {"associatedstring", 46},
    {"additionalstringproperty", 46},
    {"customstringproperty", 46},
    {"firmwarestringproperty", 46},
    {"platformstringproperty", 46},
    {"propertyvalue", 46},
    {"stringvalue", 46},
    {"type46", 46},
    {"smbiostype46", 46},
    {"dmitype46", 46},
    {"dmi46", 46},

    {NULL, -1}  // Sentinel
};

static int compact_output = 1;
static int verbose_output = 0;

static void printType0(lazybiosCTX_t *ctx) {
    printf("=== BIOS INFORMATION ===\n");
    if (!ctx->Type0) ctx->Type0 = lazybiosGetType0(ctx->Type0, ctx->DMIData);
    if (ctx->Type0) {
        printf("Vendor: %s\n", ctx->Type0->vendor ? ctx->Type0->vendor : "Not Present");
        printf("Version: %s\n", ctx->Type0->version ? ctx->Type0->version : "Not Present");
        printf("Release Date: %s\n", ctx->Type0->release_date ? ctx->Type0->release_date : "Not Present");
        if (LAZYBIOS_FIELD_STATUS(ctx->Type0, bios_starting_segment) != LAZYBIOS_FIELD_PRESENT) {
            printf("BIOS Starting Segment: Not Present\n");
        } else {
            printf("BIOS Starting Segment: 0x%04hX\n", ctx->Type0->bios_starting_segment);
        }
        if (LAZYBIOS_FIELD_STATUS(ctx->Type0, characteristics) != LAZYBIOS_FIELD_PRESENT) {
            printf("Firmware Characteristics: Not Present\n");
        } else {
            char buf[(LAZYBIOS_DECODER_BUF_SIZE * 2)];
            lazybiosType0CharacteristicsStr(ctx->Type0->characteristics, buf, sizeof(buf));
            printf("Firmware Characteristics: %s\n", buf);
        }
        if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
            if (ctx->Type0->firmware_char_ext_bytes_count >= 1 && ctx->Type0->firmware_char_ext_bytes) {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType0CharacteristicsExtByte1Str(ctx->Type0->firmware_char_ext_bytes[0], buf, sizeof(buf));
                printf("Firmware Characteristics Extension Bytes 1: %s\n", buf);
            } else {
                printf("Firmware Characteristics Extension Bytes 1: Not Present\n");
            }
        } else if (!compact_output) {
            printf("Firmware Characteristics Extension Bytes 1: [SMBIOS 2.1 required]\n");
        }
        if (lazybiosIsVersionPlus(ctx->DMIData, 2, 3)) {
            if (ctx->Type0->firmware_char_ext_bytes_count >= 2 && ctx->Type0->firmware_char_ext_bytes) {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType0CharacteristicsExtByte2Str(ctx->Type0->firmware_char_ext_bytes[1], buf, sizeof(buf));
                printf("Firmware Characteristics Extension Bytes 2: %s\n", buf);
            } else {
                printf("Firmware Characteristics Extension Bytes 2: Not Present\n");
            }
        } else if (!compact_output) {
            printf("Firmware Characteristics Extension Bytes 2: [SMBIOS 2.3 required]\n");
        }
        if (lazybiosIsVersionPlus(ctx->DMIData, 2, 4)) {
            if (LAZYBIOS_FIELD_STATUS(ctx->Type0, platform_major_release) != LAZYBIOS_FIELD_PRESENT) {
                printf("Platform Major Release: Not Present\n");
            } else {
                printf("Platform Major Release: %hhu\n", ctx->Type0->platform_major_release);
            }
            if (LAZYBIOS_FIELD_STATUS(ctx->Type0, platform_minor_release) != LAZYBIOS_FIELD_PRESENT) {
                printf("Platform Minor Release: Not Present\n");
            } else {
                printf("Platform Minor Release: %hhu\n", ctx->Type0->platform_minor_release);
            }
            if (LAZYBIOS_FIELD_STATUS(ctx->Type0, ec_major_release) != LAZYBIOS_FIELD_PRESENT) {
                printf("EC Major Release: Not Present\n");
            } else {
                printf("EC Major Release: %hhu\n", ctx->Type0->ec_major_release);
            }
            if (LAZYBIOS_FIELD_STATUS(ctx->Type0, ec_minor_release) != LAZYBIOS_FIELD_PRESENT) {
                printf("EC Minor Release: Not Present\n");
            } else {
                printf("EC Minor Release: %hhu\n", ctx->Type0->ec_minor_release);
            }
        } else {
            if (!compact_output) printf("Platform Major Release: [SMBIOS 2.4 required]\n");
            if (!compact_output) printf("Platform Minor Release: [SMBIOS 2.4 required]\n");
            if (!compact_output) printf("EC Major Release: [SMBIOS 2.4 required]\n");
            if (!compact_output) printf("EC Minor Release: [SMBIOS 2.4 required]\n");
        }
        if (LAZYBIOS_FIELD_STATUS(ctx->Type0, extended_rom_size) == LAZYBIOS_FIELD_PRESENT) {
            printf("Extended ROM Size: %hu%s\n\n", lazybiosType0ExtendedROMSizeU16(ctx->Type0->extended_rom_size, ctx->Type0->unit), ctx->Type0->unit);
        } else if (LAZYBIOS_FIELD_STATUS(ctx->Type0, rom_size) == LAZYBIOS_FIELD_PRESENT) {
            printf("ROM Size: %u KB\n\n", ctx->Type0->rom_size);
        } else {
            printf("ROM Size: Not Present\n\n");
        }
    } else {
        printf("Failed to get BIOS information\n\n");
    }
}

static void printType1(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM INFORMATION ===\n");
    if (!ctx->Type1) ctx->Type1 = lazybiosGetType1(ctx->Type1, ctx->DMIData);
    if (ctx->Type1) {
        printf("Manufacturer: %s\n", ctx->Type1->manufacturer ? ctx->Type1->manufacturer : "Not Present");
        printf("Product name: %s\n", ctx->Type1->product_name ? ctx->Type1->product_name : "Not Present");
        printf("Version: %s\n", ctx->Type1->version ? ctx->Type1->version : "Not Present");
        printf("Serial number: %s\n", ctx->Type1->serial_number ? ctx->Type1->serial_number : "Not Present");
        if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
            if (LAZYBIOS_FIELD_STATUS(ctx->Type1, uuid) == LAZYBIOS_FIELD_PRESENT) {
                printf("UUID: %02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X\n", ctx->Type1->uuid[3], ctx->Type1->uuid[2],
                       ctx->Type1->uuid[1], ctx->Type1->uuid[0], ctx->Type1->uuid[5], ctx->Type1->uuid[4], ctx->Type1->uuid[7], ctx->Type1->uuid[6],
                       ctx->Type1->uuid[8], ctx->Type1->uuid[9], ctx->Type1->uuid[10], ctx->Type1->uuid[11], ctx->Type1->uuid[12], ctx->Type1->uuid[13],
                       ctx->Type1->uuid[14], ctx->Type1->uuid[15]);
            } else {
                printf("UUID: Not Present\n");
            }
            if (LAZYBIOS_FIELD_STATUS(ctx->Type1, wake_up_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Wake up type: Not Present\n");
            } else {
                printf("Wake up type: %s\n", lazybiosType1WakeupTypeStr(ctx->Type1->wake_up_type));
            }
        } else {
            if (!compact_output) printf("UUID: [SMBIOS 2.1 required]\n");
            if (!compact_output) printf("Wake up type: [SMBIOS 2.1 required]\n");
        }
        if (lazybiosIsVersionPlus(ctx->DMIData, 2, 4)) {
            printf("SKU number: %s\n", ctx->Type1->sku_number ? ctx->Type1->sku_number : "Not Present");
            printf("Family: %s\n\n", ctx->Type1->family ? ctx->Type1->family : "Not Present");
        } else {
            if (!compact_output) printf("SKU number: [SMBIOS 2.4 required]\n");
            if (!compact_output) printf("Family: [SMBIOS 2.4 required]\n\n");
        }
    } else {
        printf("Failed to get System information\n\n");
    }
}

static void printType2(lazybiosCTX_t *ctx) {
    printf("=== BASEBOARD INFORMATION ===\n");
    if (!ctx->Type2) ctx->Type2 = lazybiosGetType2(ctx->Type2, &ctx->type2_count, ctx->DMIData);
    if (ctx->Type2 && ctx->type2_count > 0) {
        for (size_t i = 0; i < ctx->type2_count; i++) {
            lazybiosType2_t *type2 = &ctx->Type2[i];
            if (ctx->type2_count > 1) { printf("--- Baseboard %zu ---\n", i + 1); }
            printf("Manufacturer: %s\n", type2->manufacturer ? type2->manufacturer : "Not Present");
            printf("Product: %s\n", type2->product ? type2->product : "Not Present");
            printf("Version: %s\n", type2->version ? type2->version : "Not Present");
            printf("Serial number: %s\n", type2->serial_number ? type2->serial_number : "Not Present");
            printf("Asset tag: %s\n", type2->asset_tag ? type2->asset_tag : "Not Present");
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type2, feature_flags) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Feature flags: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType2FeatureflagsStr(type2->feature_flags, buf, sizeof(buf));
                    printf("Feature flags: %s\n", buf);
                }
                printf("Location in Chassis: %s\n", type2->location_in_chassis ? type2->location_in_chassis : "Not Present");
                if (LAZYBIOS_FIELD_STATUS(type2, chassis_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Chassis Handle: Not Present\n");
                } else {
                    printf("Chassis Handle: 0x%04hX\n", type2->chassis_handle);
                }
                if (LAZYBIOS_FIELD_STATUS(type2, board_type) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Board Type: Not Present\n");
                } else {
                    printf("Board Type: %s\n", lazybiosType2BoardTypeStr(type2->board_type));
                }
                if (LAZYBIOS_FIELD_STATUS(type2, number_of_contained_object_handles) != LAZYBIOS_FIELD_PRESENT ||
                    type2->number_of_contained_object_handles == 0) {
                } else {
                    for (int j = 0; j < type2->number_of_contained_object_handles; j++) {
                        printf("  Contained Object Handle %d: 0x%04hX\n", j, type2->contained_object_handles[j]);
                    }
                }
            } else {
                if (!compact_output) printf("Feature flags: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Location in Chassis: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Chassis Handle: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Board Type: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Contained Object Handles: [SMBIOS 2.1 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Baseboard information\n\n");
    }
}

static void printType3(lazybiosCTX_t *ctx) {
    printf("=== CHASSIS INFORMATION ===\n");
    if (!ctx->Type3) ctx->Type3 = lazybiosGetType3(ctx->Type3, &ctx->type3_count, ctx->DMIData);
    if (ctx->Type3 && ctx->type3_count > 0) {
        for (size_t i = 0; i < ctx->type3_count; i++) {
            lazybiosType3_t *type3 = &ctx->Type3[i];
            if (ctx->type3_count > 1) { printf("--- Chassis %zu ---\n", i + 1); }
            printf("Manufacturer: %s\n", type3->manufacturer ? type3->manufacturer : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type3, type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Type: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType3TypeStr(type3->type, buf, sizeof(buf));
                printf("Type: %s\n", buf);
            }
            printf("Version: %s\n", type3->version ? type3->version : "Not Present");
            printf("Serial Number: %s\n", type3->serial_number ? type3->serial_number : "Not Present");
            printf("Asset Tag: %s\n", type3->asset_tag ? type3->asset_tag : "Not Present");
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type3, boot_up_state) != LAZYBIOS_FIELD_PRESENT) {
                    printf("BootUp State: Not Present\n");
                } else {
                    printf("BootUp State: %s\n", lazybiosType3StateStr(type3->boot_up_state));
                }
                if (LAZYBIOS_FIELD_STATUS(type3, power_supply_state) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Power Supply State: Not Present\n");
                } else {
                    printf("Power Supply State: %s\n", lazybiosType3StateStr(type3->power_supply_state));
                }
                if (LAZYBIOS_FIELD_STATUS(type3, thermal_state) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Thermal State: Not Present\n");
                } else {
                    printf("Thermal State: %s\n", lazybiosType3StateStr(type3->thermal_state));
                }
                if (LAZYBIOS_FIELD_STATUS(type3, security_status) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Security Status: Not Present\n");
                } else {
                    printf("Security Status: %s\n", lazybiosType3SecurityStatusStr(type3->security_status));
                }
            } else {
                if (!compact_output) printf("BootUp State: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Power Supply State: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Thermal State: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Security Status: [SMBIOS 2.1 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 3)) {
                if (LAZYBIOS_FIELD_STATUS(type3, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                    printf("OEM Defined: Not Present\n");
                } else {
                    printf("OEM-defined DWORD: 0x%08X\n", type3->oem_defined);
                }
                if (LAZYBIOS_FIELD_STATUS(type3, height) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Height: Not Present\n");
                } else if (type3->height == 0x00) {
                    printf("Height: Unspecified\n");
                } else {
                    printf("Height: %hhuU\n", type3->height);
                }
                if (LAZYBIOS_FIELD_STATUS(type3, number_of_power_cords) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Number of Power Cords: Not Present\n");
                } else {
                    printf("Number of Power Cords: %hhu\n", type3->number_of_power_cords);
                }
                if (LAZYBIOS_FIELD_STATUS(type3, contained_element_count) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Contained Elements: Not Present\n");
                } else if (type3->contained_element_count == 0) {
                    printf("Contained Elements: None\n");
                } else if (!type3->contained_elements) {
                    printf("Contained Elements: Not Present\n");
                } else {
                    printf("Contained Elements (%hhu):\n", type3->contained_element_count);
                    for (uint8_t element_index = 0; element_index < type3->contained_element_count; element_index++) {
                        uint8_t *record = type3->contained_elements + element_index * type3->contained_element_record_length;
                        uint8_t type_byte = record[0];
                        uint8_t min_count = record[1];
                        uint8_t max_count = record[2];
                        char type_str[LAZYBIOS_DECODER_BUF_SIZE];
                        lazybiosType3ContainedElementTypeStr(type_byte, type_str, sizeof(type_str));
                        printf("  Element %hhu: Type = %s, Min = %hhu, Max = %hhu\n", element_index + 1, type_str, min_count, max_count);
                        for (uint8_t j = 3; j < type3->contained_element_record_length; j++) { printf("    Extra byte %hhu: 0x%02hhX\n", j, record[j]); }
                    }
                }
                if (LAZYBIOS_FIELD_STATUS(type3, contained_element_record_length) != LAZYBIOS_FIELD_PRESENT) {
                } else if (type3->contained_element_record_length > 0) {
                    printf("Contained Element Record Length: %hhu bytes\n", type3->contained_element_record_length);
                }
                if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                    printf("SKU Number: %s\n", type3->sku_number ? type3->sku_number : "Not Present");
                } else {
                    if (!compact_output) printf("SKU Number: [SMBIOS 2.7 required]\n");
                }
                if (lazybiosIsVersionPlus(ctx->DMIData, 3, 9)) {
                    if (LAZYBIOS_FIELD_STATUS(type3, rack_type) != LAZYBIOS_FIELD_PRESENT) {
                        printf("Rack Type: Not Present\n");
                    } else {
                        printf("Rack Type: 0x%02hhX\n", type3->rack_type);
                    }
                    if (LAZYBIOS_FIELD_STATUS(type3, rack_height) != LAZYBIOS_FIELD_PRESENT) {
                        printf("Rack Height (extended): Not Present\n");
                    } else {
                        printf("Rack Height (extended): %hhuU\n", type3->rack_height);
                    }
                } else {
                    if (!compact_output) printf("Rack Type: [SMBIOS 3.9 required]\n");
                    if (!compact_output) printf("Rack Height (extended): [SMBIOS 3.9 required]\n");
                }
            } else {
                if (!compact_output) printf("OEM Defined: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Height: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Number of Power Cords: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Contained Elements: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("SKU Number: [SMBIOS 2.7 required]\n");
                if (!compact_output) printf("Rack Type: [SMBIOS 3.9 required]\n");
                if (!compact_output) printf("Rack Height (extended): [SMBIOS 3.9 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Chassis Information!\n\n");
    }
}

static void printType4(lazybiosCTX_t *ctx) {
    printf("=== PROCESSOR INFORMATION ===\n");
    if (!ctx->Type4) ctx->Type4 = lazybiosGetType4(ctx->Type4, &ctx->type4_count, ctx->DMIData);
    if (ctx->Type4 && ctx->type4_count > 0) {
        for (size_t i = 0; i < ctx->type4_count; i++) {
            lazybiosType4_t *type4 = &ctx->Type4[i];
            if (ctx->type4_count > 1) { printf("--- Processor %zu ---\n", i + 1); }
            printf("Socket Designation: %s\n", type4->socket_designation ? type4->socket_designation : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type4, processor_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor Type: Not Present\n");
            } else {
                printf("Processor Type: %s\n", lazybiosType4TypeStr(type4->processor_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type4, processor_family) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor Family: Not Present\n");
            } else {
                printf("Processor Family: %s\n", lazybiosType4ProcessorFamilyStr(type4->processor_family));
            }
            printf("Processor Manufacturer: %s\n", type4->processor_manufacturer ? type4->processor_manufacturer : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type4, processor_id) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor ID: Not Present\n");
            } else {
                printf("Processor ID: %02X %02X %02X %02X %02X %02X %02X %02X\n", (unsigned int)(type4->processor_id & 0xFF),
                       (unsigned int)((type4->processor_id >> 8) & 0xFF), (unsigned int)((type4->processor_id >> 16) & 0xFF),
                       (unsigned int)((type4->processor_id >> 24) & 0xFF), (unsigned int)((type4->processor_id >> 32) & 0xFF),
                       (unsigned int)((type4->processor_id >> 40) & 0xFF), (unsigned int)((type4->processor_id >> 48) & 0xFF),
                       (unsigned int)((type4->processor_id >> 56) & 0xFF));
            }
            printf("Processor Version: %s\n", type4->processor_version ? type4->processor_version : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type4, voltage) != LAZYBIOS_FIELD_PRESENT) {
                printf("Voltage: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType4VoltageStr(type4->voltage, buf, sizeof(buf));
                printf("Voltage: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type4, external_clock) != LAZYBIOS_FIELD_PRESENT) {
                printf("External Clock: Not Present\n");
            } else {
                printf("External Clock: %u MHz\n", type4->external_clock);
            }
            if (LAZYBIOS_FIELD_STATUS(type4, max_speed) != LAZYBIOS_FIELD_PRESENT) {
                printf("Max Speed: Not Present\n");
            } else {
                printf("Max Speed: %u MHz\n", type4->max_speed);
            }
            if (LAZYBIOS_FIELD_STATUS(type4, current_speed) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current Speed: Not Present\n");
            } else {
                printf("Current Speed: %u MHz\n", type4->current_speed);
            }
            if (LAZYBIOS_FIELD_STATUS(type4, status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Status: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType4StatusStr(type4->status, buf, sizeof(buf));
                printf("Status: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type4, processor_upgrade) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor Upgrade: Not Present\n");
            } else {
                printf("Processor Upgrade: %s\n", lazybiosType4SocketTypeStr(type4->processor_upgrade));
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type4, l1_cache_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("L1 Cache Handle: Not Present\n");
                } else {
                    printf("L1 Cache Handle: 0x%04hX\n", type4->l1_cache_handle);
                }
                if (LAZYBIOS_FIELD_STATUS(type4, l2_cache_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("L2 Cache Handle: Not Present\n");
                } else {
                    printf("L2 Cache Handle: 0x%04hX\n", type4->l2_cache_handle);
                }
                if (LAZYBIOS_FIELD_STATUS(type4, l3_cache_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("L3 Cache Handle: Not Present\n");
                } else {
                    printf("L3 Cache Handle: 0x%04hX\n", type4->l3_cache_handle);
                }
            } else {
                if (!compact_output) printf("L1 Cache Handle: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("L2 Cache Handle: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("L3 Cache Handle: [SMBIOS 2.1 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 3)) {
                printf("Serial Number: %s\n", type4->serial_number ? type4->serial_number : "Not Present");
                printf("Asset Tag: %s\n", type4->asset_tag ? type4->asset_tag : "Not Present");
                printf("Part Number: %s\n", type4->part_number ? type4->part_number : "Not Present");
            } else {
                if (!compact_output) printf("Serial Number: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Asset Tag: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Part Number: [SMBIOS 2.3 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 5)) {
                uint32_t actual_core_count = 0;
                int has_core_count = 0;
                if (type4->core_count == 0xFF && (LAZYBIOS_FIELD_STATUS(type4, core_count_2) == LAZYBIOS_FIELD_PRESENT)) {
                    actual_core_count = type4->core_count_2;
                    has_core_count = 1;
                } else if (LAZYBIOS_FIELD_STATUS(type4, core_count) == LAZYBIOS_FIELD_PRESENT && type4->core_count != 0xFF) {
                    actual_core_count = type4->core_count;
                    has_core_count = 1;
                }
                if (!has_core_count) {
                    printf("Core Count: Not Present\n");
                } else {
                    printf("Core Count: %u\n", actual_core_count);
                }
                uint32_t actual_core_enabled = 0;
                int has_core_enabled = 0;
                if (type4->core_enabled == 0xFF && (LAZYBIOS_FIELD_STATUS(type4, core_enabled_2) == LAZYBIOS_FIELD_PRESENT)) {
                    actual_core_enabled = type4->core_enabled_2;
                    has_core_enabled = 1;
                } else if (LAZYBIOS_FIELD_STATUS(type4, core_enabled) == LAZYBIOS_FIELD_PRESENT && type4->core_enabled != 0xFF) {
                    actual_core_enabled = type4->core_enabled;
                    has_core_enabled = 1;
                }
                if (!has_core_enabled) {
                    printf("Core Enabled: Not Present\n");
                } else {
                    printf("Core Enabled: %u\n", actual_core_enabled);
                }
                uint32_t actual_thread_count = 0;
                int has_thread_count = 0;
                if (type4->thread_count == 0xFF && (LAZYBIOS_FIELD_STATUS(type4, thread_count_2) == LAZYBIOS_FIELD_PRESENT)) {
                    actual_thread_count = type4->thread_count_2;
                    has_thread_count = 1;
                } else if (LAZYBIOS_FIELD_STATUS(type4, thread_count) == LAZYBIOS_FIELD_PRESENT && type4->thread_count != 0xFF) {
                    actual_thread_count = type4->thread_count;
                    has_thread_count = 1;
                }
                if (!has_thread_count) {
                    printf("Thread Count: Not Present\n");
                } else {
                    printf("Thread Count: %u\n", actual_thread_count);
                }
                if (LAZYBIOS_FIELD_STATUS(type4, processor_characteristics) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Processor Characteristics: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType4CharacteristicsStr(type4->processor_characteristics, buf, sizeof(buf));
                    printf("Processor Characteristics: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type4, processor_family_2) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Processor Family 2: Not Present\n");
                } else {
                    printf("Processor Family 2: %s\n", lazybiosType4ProcessorFamilyStr(type4->processor_family_2));
                }
            } else {
                if (!compact_output) printf("Core Count: [SMBIOS 2.5 required]\n");
                if (!compact_output) printf("Core Enabled: [SMBIOS 2.5 required]\n");
                if (!compact_output) printf("Thread Count: [SMBIOS 2.5 required]\n");
                if (!compact_output) printf("Processor Characteristics: [SMBIOS 2.5 required]\n");
                if (!compact_output) printf("Processor Family 2: [SMBIOS 2.5 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 6)) {
                if (LAZYBIOS_FIELD_STATUS(type4, thread_enabled) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Thread Enabled: Not Present\n");
                } else {
                    printf("Thread Enabled: %u\n", type4->thread_enabled);
                }
            } else {
                if (!compact_output) printf("Thread Enabled: [SMBIOS 3.6 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 8)) {
                printf("Socket Type: %s\n", type4->socket_type ? type4->socket_type : "Not Present");
            } else {
                if (!compact_output) printf("Socket Type: [SMBIOS 3.8 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Processor information!\n\n");
    }
}

static void printType5(lazybiosCTX_t *ctx) {
    printf("=== MEMORY CONTROLLER INFORMATION (OBSOLETE) ===\n");
    if (!ctx->Type5) ctx->Type5 = lazybiosGetType5(ctx->Type5, &ctx->type5_count, ctx->DMIData);
    if (ctx->Type5 && ctx->type5_count > 0) {
        for (size_t i = 0; i < ctx->type5_count; i++) {
            lazybiosType5_t *type5 = &ctx->Type5[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type5_count > 1) printf("--- Memory Controller %zu ---\n", i + 1);
            if (LAZYBIOS_FIELD_STATUS(type5, error_detecting_method) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Detecting Method: Not Present\n");
            } else {
                printf("Error Detecting Method: %s\n", lazybiosType5ErrorDetectingMethodStr(type5->error_detecting_method));
            }
            if (LAZYBIOS_FIELD_STATUS(type5, error_correcting_capability) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Correcting Capability: Not Present\n");
            } else {
                lazybiosType5ErrorCorrectingCapabilityStr(type5->error_correcting_capability, buf, sizeof(buf));
                printf("Error Correcting Capability: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, supported_interleave) != LAZYBIOS_FIELD_PRESENT) {
                printf("Supported Interleave: Not Present\n");
            } else {
                printf("Supported Interleave: %s\n", lazybiosType5InterleaveStr(type5->supported_interleave));
            }
            if (LAZYBIOS_FIELD_STATUS(type5, current_interleave) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current Interleave: Not Present\n");
            } else {
                printf("Current Interleave: %s\n", lazybiosType5InterleaveStr(type5->current_interleave));
            }
            if (LAZYBIOS_FIELD_STATUS(type5, maximum_memory_module_size) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Memory Module Size: Not Present\n");
            } else if (type5->maximum_memory_module_size < 64) {
                printf("Maximum Memory Module Size: %llu MiB\n", (unsigned long long)(1ULL << type5->maximum_memory_module_size));
            } else {
                printf("Maximum Memory Module Size: 2^%hhu MiB\n", type5->maximum_memory_module_size);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, supported_speeds) != LAZYBIOS_FIELD_PRESENT) {
                printf("Supported Speeds: Not Present\n");
            } else {
                lazybiosType5SupportedSpeedsStr(type5->supported_speeds, buf, sizeof(buf));
                printf("Supported Speeds: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, supported_memory_types) != LAZYBIOS_FIELD_PRESENT) {
                printf("Supported Memory Types: Not Present\n");
            } else {
                lazybiosType5SupportedMemoryTypesStr(type5->supported_memory_types, buf, sizeof(buf));
                printf("Supported Memory Types: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, memory_module_voltage) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Module Voltage: Not Present\n");
            } else {
                lazybiosType5MemoryModuleVoltageStr(type5->memory_module_voltage, buf, sizeof(buf));
                printf("Memory Module Voltage: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, number_of_associated_memory_slots) != LAZYBIOS_FIELD_PRESENT) {
                printf("Number of Associated Memory Slots: Not Present\n");
            } else {
                printf("Number of Associated Memory Slots: %hhu\n", type5->number_of_associated_memory_slots);
            }
            if (LAZYBIOS_FIELD_STATUS(type5, memory_module_configuration_handles) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Module Configuration Handles: Not Present\n");
            } else if (type5->number_of_associated_memory_slots == 0) {
                printf("Memory Module Configuration Handles: None\n");
            } else {
                for (size_t j = 0; j < type5->number_of_associated_memory_slots; j++) {
                    printf("Memory Module Configuration Handle %zu: 0x%04hX\n", j + 1, type5->memory_module_configuration_handles[j]);
                }
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type5, enabled_error_correcting_capabilities) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Enabled Error Correcting Capabilities: Not Present\n");
                } else {
                    lazybiosType5ErrorCorrectingCapabilityStr(type5->enabled_error_correcting_capabilities, buf, sizeof(buf));
                    printf("Enabled Error Correcting Capabilities: %s\n", buf);
                }
            } else if (!compact_output) {
                printf("Enabled Error Correcting Capabilities: [SMBIOS 2.1 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Controller information\n\n");
    }
}

static void printType6(lazybiosCTX_t *ctx) {
    printf("=== MEMORY MODULE INFORMATION (OBSOLETE) ===\n");
    if (!ctx->Type6) ctx->Type6 = lazybiosGetType6(ctx->Type6, &ctx->type6_count, ctx->DMIData);
    if (ctx->Type6 && ctx->type6_count > 0) {
        for (size_t i = 0; i < ctx->type6_count; i++) {
            lazybiosType6_t *type6 = &ctx->Type6[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type6_count > 1) printf("--- Memory Module %zu ---\n", i + 1);
            printf("Socket Designation: %s\n", type6->socket_designation ? type6->socket_designation : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type6, bank_connections) != LAZYBIOS_FIELD_PRESENT) {
                printf("Bank Connections: Not Present\n");
            } else {
                lazybiosType6BankConnectionsStr(type6->bank_connections, buf, sizeof(buf));
                printf("Bank Connections: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type6, current_speed) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current Speed: Not Present\n");
            } else if (type6->current_speed == 0) {
                printf("Current Speed: Unknown\n");
            } else {
                printf("Current Speed: %hhu ns\n", type6->current_speed);
            }
            if (LAZYBIOS_FIELD_STATUS(type6, current_memory_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current Memory Type: Not Present\n");
            } else {
                lazybiosType6CurrentMemoryTypeStr(type6->current_memory_type, buf, sizeof(buf));
                printf("Current Memory Type: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type6, installed_size) != LAZYBIOS_FIELD_PRESENT) {
                printf("Installed Size: Not Present\n");
            } else {
                lazybiosType6InstalledSizeStr(type6->installed_size, buf, sizeof(buf));
                printf("Installed Size: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type6, enabled_size) != LAZYBIOS_FIELD_PRESENT) {
                printf("Enabled Size: Not Present\n");
            } else {
                lazybiosType6EnabledSizeStr(type6->enabled_size, buf, sizeof(buf));
                printf("Enabled Size: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type6, error_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Status: Not Present\n");
            } else {
                lazybiosType6ErrorStatusStr(type6->error_status, buf, sizeof(buf));
                printf("Error Status: %s\n", buf);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Module information\n\n");
    }
}

static void printType7(lazybiosCTX_t *ctx) {
    printf("=== CACHE INFORMATION ===\n");
    if (!ctx->Type7) ctx->Type7 = lazybiosGetType7(ctx->Type7, &ctx->type7_count, ctx->DMIData);
    if (ctx->Type7 && ctx->type7_count > 0) {
        for (size_t i = 0; i < ctx->type7_count; i++) {
            lazybiosType7_t *type7 = &ctx->Type7[i];
            if (ctx->type7_count > 1) { printf("--- Cache %zu ---\n", i + 1); }
            printf("Socket Designation: %s\n", type7->socket_designation ? type7->socket_designation : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type7, cache_configuration) != LAZYBIOS_FIELD_PRESENT) {
                printf("Cache Configuration: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType7CacheConfigurationStr(type7->cache_configuration, buf, sizeof(buf));
                printf("Cache Configuration: %s\n", buf);
            }
            if (type7->maximum_cache_size == 0xFFFF) {
                if (LAZYBIOS_FIELD_STATUS(type7, maximum_cache_size_2) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Maximum Cache Size: Not Present\n");
                } else {
                    uint64_t size_kb = lazybiosType7CacheU32(type7->maximum_cache_size_2);
                    if (size_kb > 1024) {
                        printf("Maximum Cache Size: %.2f MB\n", (double)size_kb / 1024.0);
                    } else {
                        printf("Maximum Cache Size: %llu KB\n", (unsigned long long)size_kb);
                    }
                }
            } else {
                uint64_t size_kb = lazybiosType7CacheU16(type7->maximum_cache_size);
                if (size_kb > 1024) {
                    printf("Maximum Cache Size: %.2f MB\n", (double)size_kb / 1024.0);
                } else {
                    printf("Maximum Cache Size: %llu KB\n", (unsigned long long)size_kb);
                }
            }
            if (type7->installed_size == 0xFFFF) {
                if (LAZYBIOS_FIELD_STATUS(type7, installed_cache_size_2) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Installed Size: Not Present\n");
                } else {
                    uint64_t size_kb = lazybiosType7CacheU32(type7->installed_cache_size_2);
                    if (size_kb > 1024) {
                        printf("Installed Size: %.2f MB\n", (double)size_kb / 1024.0);
                    } else {
                        printf("Installed Size: %llu KB\n", (unsigned long long)size_kb);
                    }
                }
            } else {
                uint64_t size_kb = lazybiosType7CacheU16(type7->installed_size);
                if (size_kb > 1024) {
                    printf("Installed Size: %.2f MB\n", (double)size_kb / 1024.0);
                } else {
                    printf("Installed Size: %llu KB\n", (unsigned long long)size_kb);
                }
            }
            if (LAZYBIOS_FIELD_STATUS(type7, supported_sram_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Supported SRAM Type: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType7SRAMTypeStr(type7->supported_sram_type, buf, sizeof(buf));
                printf("Supported SRAM Type: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type7, current_sram_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current SRAM Type: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType7SRAMTypeStr(type7->current_sram_type, buf, sizeof(buf));
                printf("Current SRAM Type: %s\n", buf);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type7, cache_speed) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Cache Speed: Not Present\n");
                } else if (type7->cache_speed == 0) {
                    printf("Cache Speed: Unknown\n");
                } else {
                    printf("Cache Speed: %hhu ns\n", type7->cache_speed);
                }
                if (LAZYBIOS_FIELD_STATUS(type7, error_correction_type) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Error Correction Type: Not Present\n");
                } else {
                    printf("Error Correction Type: %s\n", lazybiosType7ErrorCorrectionTypeStr(type7->error_correction_type));
                }
                if (LAZYBIOS_FIELD_STATUS(type7, system_cache_type) != LAZYBIOS_FIELD_PRESENT) {
                    printf("System Cache Type: Not Present\n");
                } else {
                    printf("System Cache Type: %s\n", lazybiosType7SystemCacheTypeStr(type7->system_cache_type));
                }
                if (LAZYBIOS_FIELD_STATUS(type7, associativity) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Associativity: Not Present\n");
                } else {
                    printf("Associativity: %s\n", lazybiosType7AssociativityStr(type7->associativity));
                }
            } else {
                if (!compact_output) printf("Cache Speed: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Error Correction Type: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("System Cache Type: [SMBIOS 2.1 required]\n");
                if (!compact_output) printf("Associativity: [SMBIOS 2.1 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type7, maximum_cache_size_2) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Maximum Cache Size 2: Not Present\n");
                } else {
                    uint64_t size_kb = lazybiosType7CacheU32(type7->maximum_cache_size_2);
                    if (size_kb > 1024) {
                        printf("Maximum Cache Size 2: %.2f MB\n", (double)size_kb / 1024.0);
                    } else {
                        printf("Maximum Cache Size 2: %llu KB\n", (unsigned long long)size_kb);
                    }
                }
                if (LAZYBIOS_FIELD_STATUS(type7, installed_cache_size_2) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Installed Cache Size 2: Not Present\n");
                } else {
                    uint64_t size_kb = lazybiosType7CacheU32(type7->installed_cache_size_2);
                    if (size_kb > 1024) {
                        printf("Installed Cache Size 2: %.2f MB\n", (double)size_kb / 1024.0);
                    } else {
                        printf("Installed Cache Size 2: %llu KB\n", (unsigned long long)size_kb);
                    }
                }
            } else {
                if (!compact_output) printf("Maximum Cache Size 2: [SMBIOS 3.1 required]\n");
                if (!compact_output) printf("Installed Cache Size 2: [SMBIOS 3.1 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Cache information\n\n");
    }
}

static void printType8(lazybiosCTX_t *ctx) {
    printf("=== PORT CONNECTOR INFORMATION ===\n");
    if (!ctx->Type8) ctx->Type8 = lazybiosGetType8(ctx->Type8, &ctx->type8_count, ctx->DMIData);
    if (ctx->Type8 && ctx->type8_count > 0) {
        for (size_t i = 0; i < ctx->type8_count; i++) {
            lazybiosType8_t *type8 = &ctx->Type8[i];
            if (ctx->type8_count > 1) { printf("--- Port Connector %zu ---\n", i + 1); }
            printf("Internal Reference Designator: %s\n", type8->internal_reference_designator ? type8->internal_reference_designator : "Not Present");
            printf("Internal Connector Type: %s\n", lazybiosType8ConnectorTypeStr(type8->internal_connector_type));
            printf("External Reference Designator: %s\n", type8->external_reference_designator ? type8->external_reference_designator : "Not Present");
            printf("External Connector Type: %s\n", lazybiosType8ConnectorTypeStr(type8->external_connector_type));
            printf("Port Type: %s\n", lazybiosType8PortTypeStr(type8->port_type));
            printf("\n");
        }
    } else {
        printf("Failed to get Port Connector information\n\n");
    }
}

static void printType9(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM SLOTS ===\n");
    if (!ctx->Type9) ctx->Type9 = lazybiosGetType9(ctx->Type9, &ctx->type9_count, ctx->DMIData);
    if (ctx->Type9 && ctx->type9_count > 0) {
        for (size_t i = 0; i < ctx->type9_count; i++) {
            lazybiosType9_t *type9 = &ctx->Type9[i];
            if (ctx->type9_count > 1) { printf("--- System Slot %zu ---\n", i + 1); }
            printf("Slot Designation: %s\n", type9->slot_designation ? type9->slot_designation : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type9, slot_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Slot Type: Not Present\n");
            } else {
                printf("Slot Type: %s\n", lazybiosType9SlotTypeStr(type9->slot_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type9, slot_data_bus_width) != LAZYBIOS_FIELD_PRESENT) {
                printf("Slot Data Bus Width: Not Present\n");
            } else {
                printf("Slot Data Bus Width: %s\n", lazybiosType9SlotWidthStr(type9->slot_data_bus_width));
            }
            if (LAZYBIOS_FIELD_STATUS(type9, current_usage) != LAZYBIOS_FIELD_PRESENT) {
                printf("Current Usage: Not Present\n");
            } else {
                printf("Current Usage: %s\n", lazybiosType9CurrentUsageStr(type9->current_usage));
            }
            if (LAZYBIOS_FIELD_STATUS(type9, slot_length) != LAZYBIOS_FIELD_PRESENT) {
                printf("Slot Length: Not Present\n");
            } else {
                printf("Slot Length: %s\n", lazybiosType9SlotLengthStr(type9->slot_length));
            }
            if (LAZYBIOS_FIELD_STATUS(type9, slot_id) != LAZYBIOS_FIELD_PRESENT) {
                printf("Slot ID: Not Present\n");
            } else {
                printf("Slot ID: 0x%04hX\n", type9->slot_id);
            }
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            lazybiosType9Characteristics1Str(type9->slot_characteristics_1, buf, sizeof(buf));
            printf("Slot Characteristics 1: %s\n", buf);
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                lazybiosType9Characteristics2Str(type9->slot_characteristics_2, buf, sizeof(buf));
                printf("Slot Characteristics 2: %s\n", buf);
            } else {
                if (!compact_output) printf("Slot Characteristics 2: [SMBIOS 2.1 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 6)) {
                if (LAZYBIOS_FIELD_STATUS(type9, segment_group_number) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Segment Group Number: Not Applicable\n");
                } else {
                    printf("Segment Group Number: %hu\n", type9->segment_group_number);
                }
                if (LAZYBIOS_FIELD_STATUS(type9, bus_number) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Bus Number: Not Applicable\n");
                } else {
                    printf("Bus Number: %hhu\n", type9->bus_number);
                }
                lazybiosType9DeviceFunctionStr(type9->device_function_number, buf, sizeof(buf));
                printf("Device/Function Number: %s\n", buf);
            } else {
                if (!compact_output) printf("Segment Group Number: [SMBIOS 2.6 required]\n");
                if (!compact_output) printf("Bus Number: [SMBIOS 2.6 required]\n");
                if (!compact_output) printf("Device/Function Number: [SMBIOS 2.6 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 2)) {
                if (LAZYBIOS_FIELD_STATUS(type9, data_bus_width) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Data Bus Width: Not Present\n");
                } else {
                    printf("Data Bus Width: %s\n", lazybiosType9SlotWidthStr(type9->data_bus_width));
                }
                if (LAZYBIOS_FIELD_STATUS(type9, peer_grouping_count) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Peer Grouping Count: Not Present\n");
                } else {
                    printf("Peer Grouping Count: %hhu\n", type9->peer_grouping_count);
                    for (size_t j = 0; j < type9->peer_grouping_count && type9->peer_groups; j++) {
                        lazybiosType9PeerGroup_t *peer = &type9->peer_groups[j];
                        printf("  Peer Group %zu:\n", j + 1);
                        if (LAZYBIOS_FIELD_STATUS(peer, segment_group_number) != LAZYBIOS_FIELD_PRESENT) {
                            printf("    Segment Group Number: Not Applicable\n");
                        } else {
                            printf("    Segment Group Number: %hu\n", peer->segment_group_number);
                        }
                        if (LAZYBIOS_FIELD_STATUS(peer, bus_number) != LAZYBIOS_FIELD_PRESENT) {
                            printf("    Bus Number: Not Applicable\n");
                        } else {
                            printf("    Bus Number: %hhu\n", peer->bus_number);
                        }
                        lazybiosType9DeviceFunctionStr(peer->device_function_number, buf, sizeof(buf));
                        printf("    Device/Function Number: %s\n", buf);
                        printf("    Data Bus Width: %s\n", lazybiosType9SlotWidthStr(peer->data_bus_width));
                    }
                }
            } else {
                if (!compact_output) printf("Data Bus Width: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Peer Groups: [SMBIOS 3.2 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 4)) {
                if (LAZYBIOS_FIELD_STATUS(type9, slot_information) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Slot Information: Not Present\n");
                } else if (type9->slot_type == 0xC4) {
                    printf("Slot Information: PCI Express Generation %hhu\n", type9->slot_information);
                } else {
                    printf("Slot Information: 0x%02hhX\n", type9->slot_information);
                }
                if (LAZYBIOS_FIELD_STATUS(type9, slot_physical_width) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Slot Physical Width: Not Present\n");
                } else {
                    printf("Slot Physical Width: %s\n", lazybiosType9SlotWidthStr(type9->slot_physical_width));
                }
                if (LAZYBIOS_FIELD_STATUS(type9, slot_pitch) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Slot Pitch: Not Present\n");
                } else if (type9->slot_pitch == 0) {
                    printf("Slot Pitch: Unknown\n");
                } else {
                    printf("Slot Pitch: %.2f mm\n", (double)type9->slot_pitch / 100.0);
                }
            } else {
                if (!compact_output) printf("Slot Information: [SMBIOS 3.4 required]\n");
                if (!compact_output) printf("Slot Physical Width: [SMBIOS 3.4 required]\n");
                if (!compact_output) printf("Slot Pitch: [SMBIOS 3.4 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 5)) {
                if (LAZYBIOS_FIELD_STATUS(type9, slot_height) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Slot Height: Not Present\n");
                } else {
                    printf("Slot Height: %s\n", lazybiosType9SlotHeightStr(type9->slot_height));
                }
            } else {
                if (!compact_output) printf("Slot Height: [SMBIOS 3.5 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Slot information\n\n");
    }
}

static void printType10(lazybiosCTX_t *ctx) {
    printf("=== ON BOARD DEVICES INFORMATION (OBSOLETE) ===\n");
    if (!ctx->Type10) ctx->Type10 = lazybiosGetType10(ctx->Type10, &ctx->type10_count, ctx->DMIData);
    if (ctx->Type10 && ctx->type10_count > 0) {
        for (size_t i = 0; i < ctx->type10_count; i++) {
            lazybiosType10_t *type10 = &ctx->Type10[i];
            if (ctx->type10_count > 1) printf("--- On Board Devices Structure %zu ---\n", i + 1);
            if (LAZYBIOS_FIELD_STATUS(type10, devices) != LAZYBIOS_FIELD_PRESENT) {
                printf("Devices: Not Present\n\n");
                continue;
            }
            if (type10->device_count == 0) {
                printf("Devices: None\n\n");
                continue;
            }
            for (size_t j = 0; j < type10->device_count; j++) {
                lazybiosType10Device_t *device = &type10->devices[j];
                if (type10->device_count > 1) printf("Device %zu:\n", j + 1);
                if (LAZYBIOS_FIELD_STATUS(device, device_type_and_status) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Type: Not Present\n");
                    printf("Status: Not Present\n");
                } else {
                    printf("Type: %s\n", lazybiosType10DeviceTypeStr(device->device_type_and_status));
                    printf("Status: %s\n", lazybiosType10DeviceStatusStr(device->device_type_and_status));
                }
                printf("Description: %s\n", device->description ? device->description : "Not Present");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get On Board Devices information\n\n");
    }
}

static void printType11(lazybiosCTX_t *ctx) {
    printf("=== OEM STRINGS ===\n");
    if (!ctx->Type11) ctx->Type11 = lazybiosGetType11(ctx->Type11, &ctx->type11_count, ctx->DMIData);
    if (ctx->Type11 && ctx->type11_count > 0) {
        for (size_t i = 0; i < ctx->type11_count; i++) {
            lazybiosType11_t *type11 = &ctx->Type11[i];
            if (ctx->type11_count > 1) { printf("--- OEM Strings Structure %zu ---\n", i + 1); }
            printf("String Count: %hhu\n", type11->string_count);
            for (size_t j = 0; j < type11->string_count; j++) {
                printf("OEM String %zu: %s\n", j + 1, type11->strings[j] ? type11->strings[j] : "Not Present");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get OEM Strings information\n\n");
    }
}

static void printType12(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM CONFIGURATION OPTIONS ===\n");
    if (!ctx->Type12) ctx->Type12 = lazybiosGetType12(ctx->Type12, &ctx->type12_count, ctx->DMIData);
    if (ctx->Type12 && ctx->type12_count > 0) {
        for (size_t i = 0; i < ctx->type12_count; i++) {
            lazybiosType12_t *type12 = &ctx->Type12[i];
            if (ctx->type12_count > 1) { printf("--- System Configuration Options Structure %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type12, option_count) != LAZYBIOS_FIELD_PRESENT) {
                printf("Option Count: Not Present\n");
            } else {
                printf("Option Count: %hhu\n", type12->option_count);
            }
            if (LAZYBIOS_FIELD_STATUS(type12, options) != LAZYBIOS_FIELD_PRESENT) {
                printf("Configuration Options: Not Present\n");
            } else {
                for (size_t j = 0; j < type12->option_count; j++) {
                    printf("Configuration Option %zu: %s\n", j + 1, type12->options[j] ? type12->options[j] : "Not Present");
                }
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Configuration Options information\n\n");
    }
}

static void printType13(lazybiosCTX_t *ctx) {
    printf("=== FIRMWARE LANGUAGE INFORMATION ===\n");
    if (!ctx->Type13) ctx->Type13 = lazybiosGetType13(ctx->Type13, &ctx->type13_count, ctx->DMIData);
    if (ctx->Type13 && ctx->type13_count > 0) {
        for (size_t i = 0; i < ctx->type13_count; i++) {
            lazybiosType13_t *type13 = &ctx->Type13[i];
            if (ctx->type13_count > 1) { printf("--- Firmware Language Structure %zu ---\n", i + 1); }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type13, flags) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Language Description Format: Not Present\n");
                } else {
                    printf("Language Description Format: %s\n", lazybiosType13LanguageFormatStr(type13->flags));
                }
            } else {
                if (!compact_output) printf("Language Description Format: [SMBIOS 2.1 required]\n");
            }
            if (LAZYBIOS_FIELD_STATUS(type13, installable_languages) != LAZYBIOS_FIELD_PRESENT) {
                printf("Installable Languages: Not Present\n");
            } else {
                printf("Installable Languages: %hhu\n", type13->installable_languages);
            }
            if (LAZYBIOS_FIELD_STATUS(type13, languages) != LAZYBIOS_FIELD_PRESENT) {
                printf("Languages: Not Present\n");
            } else {
                for (size_t j = 0; j < type13->installable_languages; j++) {
                    printf("Language %zu: %s\n", j + 1, type13->languages[j] ? type13->languages[j] : "Not Present");
                }
            }
            printf("Currently Installed Language: %s\n", type13->current_language ? type13->current_language : "Not Present");
            printf("\n");
        }
    } else {
        printf("Failed to get Firmware Language information\n\n");
    }
}

static void printType14(lazybiosCTX_t *ctx) {
    printf("=== GROUP ASSOCIATIONS ===\n");
    if (!ctx->Type14) ctx->Type14 = lazybiosGetType14(ctx->Type14, &ctx->type14_count, ctx->DMIData);
    if (ctx->Type14 && ctx->type14_count > 0) {
        for (size_t i = 0; i < ctx->type14_count; i++) {
            lazybiosType14_t *type14 = &ctx->Type14[i];
            if (ctx->type14_count > 1) { printf("--- Group Association %zu ---\n", i + 1); }
            printf("Group Name: %s\n", type14->group_name ? type14->group_name : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type14, item_count) != LAZYBIOS_FIELD_PRESENT) {
                printf("Item Count: Not Present\n");
            } else {
                printf("Item Count: %zu\n", type14->item_count);
            }
            if (LAZYBIOS_FIELD_STATUS(type14, items) != LAZYBIOS_FIELD_PRESENT) {
                printf("Items: Not Present\n");
            } else {
                for (size_t j = 0; j < type14->item_count; j++) {
                    lazybiosType14Item_t *item = &type14->items[j];
                    printf("Item %zu Type: %hhu\n", j + 1, item->item_type);
                    printf("Item %zu Handle: 0x%04hX\n", j + 1, item->item_handle);
                }
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Group Associations information\n\n");
    }
}

static void printType15(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM EVENT LOG ===\n");
    if (!ctx->Type15) ctx->Type15 = lazybiosGetType15(ctx->Type15, &ctx->type15_count, ctx->DMIData);
    if (ctx->Type15 && ctx->type15_count > 0) {
        for (size_t i = 0; i < ctx->type15_count; i++) {
            lazybiosType15_t *type15 = &ctx->Type15[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type15_count > 1) { printf("--- System Event Log %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type15, log_area_length) != LAZYBIOS_FIELD_PRESENT) {
                printf("Log Area Length: Not Present\n");
            } else {
                printf("Log Area Length: %hu bytes\n", type15->log_area_length);
            }
            if (LAZYBIOS_FIELD_STATUS(type15, log_header_start_offset) != LAZYBIOS_FIELD_PRESENT) {
                printf("Log Header Start Offset: Not Present\n");
            } else {
                printf("Log Header Start Offset: 0x%04hX\n", type15->log_header_start_offset);
            }
            if (LAZYBIOS_FIELD_STATUS(type15, log_data_start_offset) != LAZYBIOS_FIELD_PRESENT) {
                printf("Log Data Start Offset: Not Present\n");
            } else {
                printf("Log Data Start Offset: 0x%04hX\n", type15->log_data_start_offset);
            }
            if (LAZYBIOS_FIELD_STATUS(type15, access_method) != LAZYBIOS_FIELD_PRESENT) {
                printf("Access Method: Not Present\n");
            } else {
                printf("Access Method: %s\n", lazybiosType15AccessMethodStr(type15->access_method));
            }
            if (LAZYBIOS_FIELD_STATUS(type15, log_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Log Status: Not Present\n");
            } else {
                lazybiosType15LogStatusStr(type15->log_status, buf, sizeof(buf));
                printf("Log Status: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type15, log_change_token) != LAZYBIOS_FIELD_PRESENT) {
                printf("Log Change Token: Not Present\n");
            } else if (type15->log_change_token == 0) {
                printf("Log Change Token: Not Implemented\n");
            } else {
                printf("Log Change Token: 0x%08X\n", type15->log_change_token);
            }
            if (LAZYBIOS_FIELD_STATUS(type15, access_method_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Access Method Address: Not Present\n");
            } else if (LAZYBIOS_FIELD_STATUS(type15, access_method) == LAZYBIOS_FIELD_PRESENT && type15->access_method <= 0x02) {
                printf("Index Address: 0x%04hX\n", lazybiosType15IndexAddress(type15->access_method_address));
                printf("Data Address: 0x%04hX\n", lazybiosType15DataAddress(type15->access_method_address));
            } else if (LAZYBIOS_FIELD_STATUS(type15, access_method) == LAZYBIOS_FIELD_PRESENT && type15->access_method == 0x03) {
                printf("Physical Address: 0x%08X\n", type15->access_method_address);
            } else if (LAZYBIOS_FIELD_STATUS(type15, access_method) == LAZYBIOS_FIELD_PRESENT && type15->access_method == 0x04) {
                printf("GPNV Handle: 0x%04hX\n", lazybiosType15GPNVHandle(type15->access_method_address));
            } else {
                printf("Access Method Address: 0x%08X\n", type15->access_method_address);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type15, log_header_format) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Log Header Format: Not Present\n");
                } else {
                    printf("Log Header Format: %s\n", lazybiosType15LogHeaderFormatStr(type15->log_header_format));
                }
                if (LAZYBIOS_FIELD_STATUS(type15, number_of_supported_log_type_descriptors) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Supported Log Type Descriptor Count: Not Present\n");
                } else {
                    printf("Supported Log Type Descriptor Count: %hhu\n", type15->number_of_supported_log_type_descriptors);
                }
                if (LAZYBIOS_FIELD_STATUS(type15, length_of_each_log_type_descriptor) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Log Type Descriptor Length: Not Present\n");
                } else {
                    printf("Log Type Descriptor Length: %hhu bytes\n", type15->length_of_each_log_type_descriptor);
                }
                if (LAZYBIOS_FIELD_STATUS(type15, supported_log_type_descriptors) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Supported Log Type Descriptors: Not Present\n");
                } else {
                    for (size_t j = 0; j < type15->number_of_supported_log_type_descriptors; j++) {
                        lazybiosType15LogTypeDescriptor_t *descriptor = &type15->supported_log_type_descriptors[j];
                        printf("Descriptor %zu Log Type: %s\n", j + 1, lazybiosType15LogTypeStr(descriptor->log_type));
                        printf("Descriptor %zu Variable Data Format: %s\n", j + 1,
                               lazybiosType15VariableDataFormatTypeStr(descriptor->variable_data_format_type));
                    }
                }
            } else if (!compact_output) {
                printf("Log Header Format: [SMBIOS 2.1 required]\n");
                printf("Supported Log Type Descriptors: [SMBIOS 2.1 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Event Log information\n\n");
    }
}

static void printType16(lazybiosCTX_t *ctx) {
    printf("=== PHYSICAL MEMORY ARRAY ===\n");
    if (!ctx->Type16) ctx->Type16 = lazybiosGetType16(ctx->Type16, &ctx->type16_count, ctx->DMIData);
    if (ctx->Type16 && ctx->type16_count > 0) {
        for (size_t i = 0; i < ctx->type16_count; i++) {
            lazybiosType16_t *type16 = &ctx->Type16[i];
            if (ctx->type16_count > 1) { printf("--- Physical Memory Array %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type16, location) != LAZYBIOS_FIELD_PRESENT) {
                printf("Location: Not Present\n");
            } else {
                printf("Location: %s\n", lazybiosType16LocationStr(type16->location));
            }
            if (LAZYBIOS_FIELD_STATUS(type16, use) != LAZYBIOS_FIELD_PRESENT) {
                printf("Use: Not Present\n");
            } else {
                printf("Use: %s\n", lazybiosType16UseStr(type16->use));
            }
            if (LAZYBIOS_FIELD_STATUS(type16, memory_error_correction) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Error Correction: Not Present\n");
            } else {
                printf("Memory Error Correction: %s\n", lazybiosType16MemoryErrorCorrectionStr(type16->memory_error_correction));
            }
            if (LAZYBIOS_FIELD_STATUS(type16, maximum_capacity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Capacity: Not Present\n");
            } else if (type16->maximum_capacity == 0x80000000U && LAZYBIOS_FIELD_STATUS(type16, extended_maximum_capacity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Capacity: Not Present\n");
            } else {
                uint64_t capacity = lazybiosType16MaximumCapacityBytes(type16->maximum_capacity, type16->extended_maximum_capacity);
                if (capacity % (1024ULL * 1024 * 1024 * 1024) == 0) {
                    printf("Maximum Capacity: %llu TiB\n", (unsigned long long)(capacity / (1024ULL * 1024 * 1024 * 1024)));
                } else if (capacity % (1024ULL * 1024 * 1024) == 0) {
                    printf("Maximum Capacity: %llu GiB\n", (unsigned long long)(capacity / (1024ULL * 1024 * 1024)));
                } else if (capacity % (1024ULL * 1024) == 0) {
                    printf("Maximum Capacity: %llu MiB\n", (unsigned long long)(capacity / (1024ULL * 1024)));
                } else {
                    printf("Maximum Capacity: %llu bytes\n", (unsigned long long)capacity);
                }
            }
            if (type16->memory_error_information_handle == 0xFFFE) {
                printf("Memory Error Information Handle: Not Provided\n");
            } else if (type16->memory_error_information_handle == 0xFFFF) {
                printf("Memory Error Information Handle: No Error Detected\n");
            } else if (LAZYBIOS_FIELD_STATUS(type16, memory_error_information_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Error Information Handle: Not Present\n");
            } else {
                printf("Memory Error Information Handle: 0x%04hX\n", type16->memory_error_information_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type16, number_of_memory_devices) != LAZYBIOS_FIELD_PRESENT) {
                printf("Number of Memory Devices: Not Present\n");
            } else {
                printf("Number of Memory Devices: %hu\n", type16->number_of_memory_devices);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                if (LAZYBIOS_FIELD_STATUS(type16, extended_maximum_capacity) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Maximum Capacity: Not Present\n");
                } else if (type16->maximum_capacity != 0x80000000U) {
                    printf("Extended Maximum Capacity: Not Used\n");
                } else {
                    printf("Extended Maximum Capacity: %llu bytes\n", (unsigned long long)type16->extended_maximum_capacity);
                }
            } else if (!compact_output) {
                printf("Extended Maximum Capacity: [SMBIOS 2.7 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Physical Memory Array information\n\n");
    }
}

static void printType17(lazybiosCTX_t *ctx) {
    printf("=== MEMORY DEVICE ===\n");
    if (!ctx->Type17) ctx->Type17 = lazybiosGetType17(ctx->Type17, &ctx->type17_count, ctx->DMIData);
    if (ctx->Type17 && ctx->type17_count > 0) {
        for (size_t i = 0; i < ctx->type17_count; i++) {
            lazybiosType17_t *type17 = &ctx->Type17[i];
            if (ctx->type17_count > 1) { printf("--- Memory Device %zu ---\n", i + 1); }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 1)) {
                if (LAZYBIOS_FIELD_STATUS(type17, physical_memory_array_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Physical Memory Array Handle: Not Present\n");
                } else {
                    printf("Physical Memory Array Handle: 0x%04hX\n", type17->physical_memory_array_handle);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, memory_error_information_handle) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Error Information Handle: Not Present\n");
                } else {
                    printf("Memory Error Information Handle: 0x%04hX\n", type17->memory_error_information_handle);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, total_width) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Total Width: Not Present\n");
                } else {
                    printf("Total Width: %u bits\n", type17->total_width == 0xFFFF ? 0 : type17->total_width);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, data_width) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Data Width: Not Present\n");
                } else {
                    printf("Data Width: %u bits\n", type17->data_width == 0xFFFF ? 0 : type17->data_width);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Size: Not Present\n");
                } else {
                    if (type17->size == 0) printf("Size: No Module Installed\n");
                    else if (type17->size == 0xFFFF) printf("Size: Unknown\n");
                    else printf("Size: %u %s\n", (type17->size & 0x7FFF), (type17->size & 0x8000) ? "KB" : "MB");
                }
                if (LAZYBIOS_FIELD_STATUS(type17, form_factor) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Form Factor: Not Present\n");
                } else {
                    printf("Form Factor: %s\n", lazybiosType17FormFactorStr(type17->form_factor));
                }
                if (LAZYBIOS_FIELD_STATUS(type17, device_set) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Device Set: Not Present\n");
                } else {
                    printf("Device Set: %u\n", type17->device_set);
                }
                printf("Device Locator: %s\n", type17->device_locator ? type17->device_locator : "Not Present");
                printf("Bank Locator: %s\n", type17->bank_locator ? type17->bank_locator : "Not Present");
                if (LAZYBIOS_FIELD_STATUS(type17, memory_type) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Type: Not Present\n");
                } else {
                    printf("Memory Type: %s\n", lazybiosType17TypeStr(type17->memory_type));
                }
                if (LAZYBIOS_FIELD_STATUS(type17, type_detail) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Type Detail: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17TypeDetailStr(type17->type_detail, buf, sizeof(buf));
                    printf("Type Detail: %s\n", buf);
                }
            } else {
                if (!compact_output) printf("[SMBIOS 2.1 required for Memory Device details]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 3)) {
                if (LAZYBIOS_FIELD_STATUS(type17, speed) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Speed: Not Present\n");
                } else {
                    printf("Speed: %u MT/s\n", type17->speed == 0xFFFF ? 0 : type17->speed);
                }
                printf("Manufacturer: %s\n", type17->manufacturer ? type17->manufacturer : "Not Present");
                printf("Serial Number: %s\n", type17->serial_number ? type17->serial_number : "Not Present");
                printf("Asset Tag: %s\n", type17->asset_tag ? type17->asset_tag : "Not Present");
                printf("Part Number: %s\n", type17->part_number ? type17->part_number : "Not Present");
            } else {
                if (!compact_output) printf("Speed: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Manufacturer: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Serial Number: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Asset Tag: [SMBIOS 2.3 required]\n");
                if (!compact_output) printf("Part Number: [SMBIOS 2.3 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 6)) {
                if (LAZYBIOS_FIELD_STATUS(type17, attributes) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Attributes: Not Present\n");
                } else {
                    printf("Attributes: %u rank(s)\n", type17->attributes & 0x7F);
                }
            } else {
                if (!compact_output) printf("Attributes: [SMBIOS 2.6 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                if (LAZYBIOS_FIELD_STATUS(type17, extended_size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Size: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17ExtendedSizeStr(type17->extended_size, buf, sizeof(buf));
                    printf("Extended Size: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, configured_memory_speed) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Configured Memory Speed: Not Present\n");
                } else {
                    printf("Configured Memory Speed: %u MT/s\n", type17->configured_memory_speed == 0xFFFF ? 0 : type17->configured_memory_speed);
                }
            } else {
                if (!compact_output) printf("Extended Size: [SMBIOS 2.7 required]\n");
                if (!compact_output) printf("Configured Memory Speed: [SMBIOS 2.7 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 8)) {
                if (LAZYBIOS_FIELD_STATUS(type17, minimum_voltage) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Minimum Voltage: Not Present\n");
                } else {
                    printf("Minimum Voltage: %u mV\n", type17->minimum_voltage);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, maximum_voltage) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Maximum Voltage: Not Present\n");
                } else {
                    printf("Maximum Voltage: %u mV\n", type17->maximum_voltage);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, configured_voltage) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Configured Voltage: Not Present\n");
                } else {
                    printf("Configured Voltage: %u mV\n", type17->configured_voltage);
                }
            } else {
                if (!compact_output) printf("Minimum Voltage: [SMBIOS 2.8 required]\n");
                if (!compact_output) printf("Maximum Voltage: [SMBIOS 2.8 required]\n");
                if (!compact_output) printf("Configured Voltage: [SMBIOS 2.8 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 2)) {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                if (LAZYBIOS_FIELD_STATUS(type17, memory_technology) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Technology: Not Present\n");
                } else {
                    printf("Memory Technology: %s\n", lazybiosType17MemoryTechnologyStr(type17->memory_technology));
                }
                if (LAZYBIOS_FIELD_STATUS(type17, memory_operating_mode_capability) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Operating Mode Capability: Not Present\n");
                } else {
                    lazybiosType17OperatingModeCapabilityStr(type17->memory_operating_mode_capability, buf, sizeof(buf));
                    printf("Memory Operating Mode Capability: %s\n", buf);
                }
                printf("Firmware Version: %s\n", type17->firmware_version ? type17->firmware_version : "Not Present");
                if (LAZYBIOS_FIELD_STATUS(type17, module_manufacturer_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Module Manufacturer ID: Not Present\n");
                } else {
                    lazybiosType17ModuleManufacturerIDStr(type17->module_manufacturer_id, buf, sizeof(buf));
                    printf("Module Manufacturer ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, module_product_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Module Product ID: Not Present\n");
                } else {
                    lazybiosType17ModuleManufacturerIDStr(type17->module_product_id, buf, sizeof(buf));
                    printf("Module Product ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, memory_subsystem_controller_manufacturer_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Subsystem Controller Manufacturer ID: Not Present\n");
                } else {
                    lazybiosType17ModuleManufacturerIDStr(type17->memory_subsystem_controller_manufacturer_id, buf, sizeof(buf));
                    printf("Memory Subsystem Controller Manufacturer ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, memory_subsystem_controller_product_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Memory Subsystem Controller Product ID: Not Present\n");
                } else {
                    lazybiosType17ModuleManufacturerIDStr(type17->memory_subsystem_controller_product_id, buf, sizeof(buf));
                    printf("Memory Subsystem Controller Product ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, non_volatile_size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Non-volatile Size: Not Present\n");
                } else {
                    lazybiosType17NonVolatileSizeStr(type17->non_volatile_size, buf, sizeof(buf));
                    printf("Non-volatile Size: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, volatile_size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Volatile Size: Not Present\n");
                } else {
                    lazybiosType17VolatileSizeStr(type17->volatile_size, buf, sizeof(buf));
                    printf("Volatile Size: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, cache_size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Cache Size: Not Present\n");
                } else {
                    lazybiosType17CacheSizeStr(type17->cache_size, buf, sizeof(buf));
                    printf("Cache Size: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, logical_size) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Logical Size: Not Present\n");
                } else {
                    printf("Logical Size: %llu bytes\n", (unsigned long long)type17->logical_size);
                }
            } else {
                if (!compact_output) printf("Memory Technology: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Memory Operating Mode Capability: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Firmware Version: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Module Manufacturer ID: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Module Product ID: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Memory Subsystem Controller Manufacturer ID: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Memory Subsystem Controller Product ID: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Non-volatile Size: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Volatile Size: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Cache Size: [SMBIOS 3.2 required]\n");
                if (!compact_output) printf("Logical Size: [SMBIOS 3.2 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 3)) {
                if (LAZYBIOS_FIELD_STATUS(type17, extended_speed) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Speed: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17ExtendedSpeedStr(type17->extended_speed, buf, sizeof(buf));
                    printf("Extended Speed: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, extended_configured_memory_speed) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Configured Memory Speed: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17ExtendedSpeedStr(type17->extended_configured_memory_speed, buf, sizeof(buf));
                    printf("Extended Configured Memory Speed: %s\n", buf);
                }
            } else {
                if (!compact_output) printf("Extended Speed: [SMBIOS 3.3 required]\n");
                if (!compact_output) printf("Extended Configured Memory Speed: [SMBIOS 3.3 required]\n");
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 3, 7)) {
                if (LAZYBIOS_FIELD_STATUS(type17, pmic0_manufacturer_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("PMIC0 Manufacturer ID: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17PMIC0ManufacturerIDStr(type17->pmic0_manufacturer_id, buf, sizeof(buf));
                    printf("PMIC0 Manufacturer ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, pmic0_revision_number) != LAZYBIOS_FIELD_PRESENT) {
                    printf("PMIC0 Revision Number: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17PMIC0RevisionStr(type17->pmic0_revision_number, buf, sizeof(buf));
                    printf("PMIC0 Revision Number: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, rcd_manufacturer_id) != LAZYBIOS_FIELD_PRESENT) {
                    printf("RCD Manufacturer ID: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17RCDManufacturerIDStr(type17->rcd_manufacturer_id, buf, sizeof(buf));
                    printf("RCD Manufacturer ID: %s\n", buf);
                }
                if (LAZYBIOS_FIELD_STATUS(type17, rcd_revision_number) != LAZYBIOS_FIELD_PRESENT) {
                    printf("RCD Revision Number: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType17RCDRevisionStr(type17->rcd_revision_number, buf, sizeof(buf));
                    printf("RCD Revision Number: %s\n", buf);
                }
            } else {
                if (!compact_output) printf("PMIC0 Manufacturer ID: [SMBIOS 3.7 required]\n");
                if (!compact_output) printf("PMIC0 Revision Number: [SMBIOS 3.7 required]\n");
                if (!compact_output) printf("RCD Manufacturer ID: [SMBIOS 3.7 required]\n");
                if (!compact_output) printf("RCD Revision Number: [SMBIOS 3.7 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Device information\n\n");
    }
}

static void printType18(lazybiosCTX_t *ctx) {
    printf("=== 32-BIT MEMORY ERROR INFORMATION ===\n");
    if (!ctx->Type18) ctx->Type18 = lazybiosGetType18(ctx->Type18, &ctx->type18_count, ctx->DMIData);
    if (ctx->Type18 && ctx->type18_count > 0) {
        for (size_t i = 0; i < ctx->type18_count; i++) {
            lazybiosType18_t *type18 = &ctx->Type18[i];
            if (ctx->type18_count > 1) { printf("--- Memory Error Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type18, error_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Type: Not Present\n");
            } else {
                printf("Error Type: %s\n", lazybiosType18ErrorTypeStr(type18->error_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type18, error_granularity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Granularity: Not Present\n");
            } else {
                printf("Error Granularity: %s\n", lazybiosType18ErrorGranularityStr(type18->error_granularity));
            }
            if (LAZYBIOS_FIELD_STATUS(type18, error_operation) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Operation: Not Present\n");
            } else {
                printf("Error Operation: %s\n", lazybiosType18ErrorOperationStr(type18->error_operation));
            }
            if (LAZYBIOS_FIELD_STATUS(type18, vendor_syndrome) != LAZYBIOS_FIELD_PRESENT) {
                printf("Vendor Syndrome: Not Present\n");
            } else if (type18->vendor_syndrome == 0) {
                printf("Vendor Syndrome: Unknown\n");
            } else {
                printf("Vendor Syndrome: 0x%08X\n", type18->vendor_syndrome);
            }
            if (LAZYBIOS_FIELD_STATUS(type18, memory_array_error_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Array Error Address: Not Present\n");
            } else if (type18->memory_array_error_address == 0x80000000U) {
                printf("Memory Array Error Address: Unknown\n");
            } else {
                printf("Memory Array Error Address: 0x%08X\n", type18->memory_array_error_address);
            }
            if (LAZYBIOS_FIELD_STATUS(type18, device_error_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Error Address: Not Present\n");
            } else if (type18->device_error_address == 0x80000000U) {
                printf("Device Error Address: Unknown\n");
            } else {
                printf("Device Error Address: 0x%08X\n", type18->device_error_address);
            }
            if (LAZYBIOS_FIELD_STATUS(type18, error_resolution) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Resolution: Not Present\n");
            } else if (type18->error_resolution == 0x80000000U) {
                printf("Error Resolution: Unknown\n");
            } else {
                printf("Error Resolution: %u bytes\n", type18->error_resolution);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get 32-Bit Memory Error information\n\n");
    }
}

static void printType19(lazybiosCTX_t *ctx) {
    printf("=== MEMORY ARRAY MAPPED ADDRESS ===\n");
    if (!ctx->Type19) ctx->Type19 = lazybiosGetType19(ctx->Type19, &ctx->type19_count, ctx->DMIData);
    if (ctx->Type19 && ctx->type19_count > 0) {
        for (size_t i = 0; i < ctx->type19_count; i++) {
            lazybiosType19_t *type19 = &ctx->Type19[i];
            if (ctx->type19_count > 1) { printf("--- Memory Array Mapped Address %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type19, starting_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Starting Address: Not Present\n");
            } else if (type19->starting_address == 0xFFFFFFFFU && LAZYBIOS_FIELD_STATUS(type19, extended_starting_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Starting Address: Not Present\n");
            } else {
                printf("Starting Address: 0x%016llX\n",
                       (unsigned long long)lazybiosType19StartingAddressBytes(type19->starting_address, type19->extended_starting_address));
            }
            if (LAZYBIOS_FIELD_STATUS(type19, ending_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Ending Address: Not Present\n");
            } else if (type19->ending_address == 0xFFFFFFFFU && LAZYBIOS_FIELD_STATUS(type19, extended_ending_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Ending Address: Not Present\n");
            } else {
                printf("Ending Address: 0x%016llX\n",
                       (unsigned long long)lazybiosType19EndingAddressBytes(type19->ending_address, type19->extended_ending_address));
            }
            if (LAZYBIOS_FIELD_STATUS(type19, memory_array_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Array Handle: Not Present\n");
            } else {
                printf("Memory Array Handle: 0x%04hX\n", type19->memory_array_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type19, partition_width) != LAZYBIOS_FIELD_PRESENT) {
                printf("Partition Width: Not Present\n");
            } else {
                printf("Partition Width: %hhu\n", type19->partition_width);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                if (LAZYBIOS_FIELD_STATUS(type19, extended_starting_address) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Starting Address: Not Present\n");
                } else if (type19->starting_address != 0xFFFFFFFFU) {
                    printf("Extended Starting Address: Not Used\n");
                } else {
                    printf("Extended Starting Address: 0x%016llX\n", (unsigned long long)type19->extended_starting_address);
                }
                if (LAZYBIOS_FIELD_STATUS(type19, extended_ending_address) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Ending Address: Not Present\n");
                } else if (type19->ending_address != 0xFFFFFFFFU) {
                    printf("Extended Ending Address: Not Used\n");
                } else {
                    printf("Extended Ending Address: 0x%016llX\n", (unsigned long long)type19->extended_ending_address);
                }
            } else if (!compact_output) {
                printf("Extended Starting Address: [SMBIOS 2.7 required]\n");
                printf("Extended Ending Address: [SMBIOS 2.7 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Array Mapped Address information\n\n");
    }
}

static void printType20(lazybiosCTX_t *ctx) {
    printf("=== MEMORY DEVICE MAPPED ADDRESS ===\n");
    if (!ctx->Type20) ctx->Type20 = lazybiosGetType20(ctx->Type20, &ctx->type20_count, ctx->DMIData);
    if (ctx->Type20 && ctx->type20_count > 0) {
        for (size_t i = 0; i < ctx->type20_count; i++) {
            lazybiosType20_t *type20 = &ctx->Type20[i];
            if (ctx->type20_count > 1) { printf("--- Memory Device Mapped Address %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type20, starting_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Starting Address: Not Present\n");
            } else if (type20->starting_address == 0xFFFFFFFFU && LAZYBIOS_FIELD_STATUS(type20, extended_starting_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Starting Address: Not Present\n");
            } else {
                printf("Starting Address: 0x%016llX\n",
                       (unsigned long long)lazybiosType20StartingAddressBytes(type20->starting_address, type20->extended_starting_address));
            }
            if (LAZYBIOS_FIELD_STATUS(type20, ending_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Ending Address: Not Present\n");
            } else if (type20->ending_address == 0xFFFFFFFFU && LAZYBIOS_FIELD_STATUS(type20, extended_ending_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Ending Address: Not Present\n");
            } else {
                printf("Ending Address: 0x%016llX\n",
                       (unsigned long long)lazybiosType20EndingAddressBytes(type20->ending_address, type20->extended_ending_address));
            }
            if (LAZYBIOS_FIELD_STATUS(type20, memory_device_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Device Handle: Not Present\n");
            } else {
                printf("Memory Device Handle: 0x%04hX\n", type20->memory_device_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type20, memory_array_mapped_address_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Array Mapped Address Handle: Not Present\n");
            } else {
                printf("Memory Array Mapped Address Handle: 0x%04hX\n", type20->memory_array_mapped_address_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type20, partition_row_position) != LAZYBIOS_FIELD_PRESENT) {
                printf("Partition Row Position: Not Present\n");
            } else if (type20->partition_row_position == 0xFF) {
                printf("Partition Row Position: Unknown\n");
            } else if (type20->partition_row_position == 0) {
                printf("Partition Row Position: Reserved\n");
            } else {
                printf("Partition Row Position: %hhu\n", type20->partition_row_position);
            }
            if (LAZYBIOS_FIELD_STATUS(type20, interleave_position) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interleave Position: Not Present\n");
            } else if (type20->interleave_position == 0xFF) {
                printf("Interleave Position: Unknown\n");
            } else if (type20->interleave_position == 0) {
                printf("Interleave Position: Non-interleaved\n");
            } else {
                printf("Interleave Position: %hhu\n", type20->interleave_position);
            }
            if (LAZYBIOS_FIELD_STATUS(type20, interleaved_data_depth) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interleaved Data Depth: Not Present\n");
            } else if (type20->interleaved_data_depth == 0xFF) {
                printf("Interleaved Data Depth: Unknown\n");
            } else if (type20->interleaved_data_depth == 0) {
                printf("Interleaved Data Depth: Not Interleaved\n");
            } else {
                printf("Interleaved Data Depth: %hhu rows\n", type20->interleaved_data_depth);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                if (LAZYBIOS_FIELD_STATUS(type20, extended_starting_address) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Starting Address: Not Present\n");
                } else if (type20->starting_address != 0xFFFFFFFFU) {
                    printf("Extended Starting Address: Not Used\n");
                } else {
                    printf("Extended Starting Address: 0x%016llX\n", (unsigned long long)type20->extended_starting_address);
                }
                if (LAZYBIOS_FIELD_STATUS(type20, extended_ending_address) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Extended Ending Address: Not Present\n");
                } else if (type20->ending_address != 0xFFFFFFFFU) {
                    printf("Extended Ending Address: Not Used\n");
                } else {
                    printf("Extended Ending Address: 0x%016llX\n", (unsigned long long)type20->extended_ending_address);
                }
            } else if (!compact_output) {
                printf("Extended Starting Address: [SMBIOS 2.7 required]\n");
                printf("Extended Ending Address: [SMBIOS 2.7 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Device Mapped Address information\n\n");
    }
}

static void printType21(lazybiosCTX_t *ctx) {
    printf("=== BUILT-IN POINTING DEVICE ===\n");
    if (!ctx->Type21) ctx->Type21 = lazybiosGetType21(ctx->Type21, &ctx->type21_count, ctx->DMIData);
    if (ctx->Type21 && ctx->type21_count > 0) {
        for (size_t i = 0; i < ctx->type21_count; i++) {
            lazybiosType21_t *type21 = &ctx->Type21[i];
            if (ctx->type21_count > 1) { printf("--- Built-in Pointing Device %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type21, pointing_device_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Type: Not Present\n");
            } else {
                printf("Type: %s\n", lazybiosType21PointingDeviceTypeStr(type21->pointing_device_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type21, interface) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interface: Not Present\n");
            } else {
                printf("Interface: %s\n", lazybiosType21InterfaceStr(type21->interface));
            }
            if (LAZYBIOS_FIELD_STATUS(type21, number_of_buttons) != LAZYBIOS_FIELD_PRESENT) {
                printf("Number of Buttons: Not Present\n");
            } else {
                printf("Number of Buttons: %hhu\n", type21->number_of_buttons);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Built-in Pointing Device information\n\n");
    }
}

static void printType22(lazybiosCTX_t *ctx) {
    printf("=== PORTABLE BATTERY ===\n");
    if (!ctx->Type22) ctx->Type22 = lazybiosGetType22(ctx->Type22, &ctx->type22_count, ctx->DMIData);
    if (ctx->Type22 && ctx->type22_count > 0) {
        for (size_t i = 0; i < ctx->type22_count; i++) {
            lazybiosType22_t *type22 = &ctx->Type22[i];
            if (ctx->type22_count > 1) { printf("--- Portable Battery %zu ---\n", i + 1); }
            printf("Location: %s\n", type22->location ? type22->location : "Not Present");
            printf("Manufacturer: %s\n", type22->manufacturer ? type22->manufacturer : "Not Present");
            printf("Manufacture Date: %s\n", type22->manufacture_date ? type22->manufacture_date : "Not Present");
            printf("Serial Number: %s\n", type22->serial_number ? type22->serial_number : "Not Present");
            printf("Device Name: %s\n", type22->device_name ? type22->device_name : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type22, device_chemistry) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Chemistry: Not Present\n");
            } else {
                printf("Device Chemistry: %s\n", lazybiosType22DeviceChemistryStr(type22->device_chemistry));
            }
            if (LAZYBIOS_FIELD_STATUS(type22, design_capacity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Design Capacity: Not Present\n");
            } else if (type22->design_capacity == 0) {
                printf("Design Capacity: Unknown\n");
            } else if (lazybiosIsVersionPlus(ctx->DMIData, 2, 2) && LAZYBIOS_FIELD_STATUS(type22, design_capacity_multiplier) != LAZYBIOS_FIELD_PRESENT) {
                printf("Design Capacity: %hu mWh (raw; multiplier not present)\n", type22->design_capacity);
            } else {
                uint8_t multiplier = lazybiosIsVersionPlus(ctx->DMIData, 2, 2) ? type22->design_capacity_multiplier : 1;
                printf("Design Capacity: %u mWh\n", lazybiosType22DesignCapacityMWh(type22->design_capacity, multiplier));
            }
            if (LAZYBIOS_FIELD_STATUS(type22, design_voltage) != LAZYBIOS_FIELD_PRESENT) {
                printf("Design Voltage: Not Present\n");
            } else if (type22->design_voltage == 0) {
                printf("Design Voltage: Unknown\n");
            } else {
                printf("Design Voltage: %hu mV\n", type22->design_voltage);
            }
            printf("SBDS Version Number: %s\n", type22->sbds_version_number ? type22->sbds_version_number : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type22, maximum_error) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Error in Battery Data: Not Present\n");
            } else if (type22->maximum_error == 0xFF) {
                printf("Maximum Error in Battery Data: Unknown\n");
            } else {
                printf("Maximum Error in Battery Data: %hhu%%\n", type22->maximum_error);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 2)) {
                if (type22->serial_number) {
                    printf("SBDS Serial Number: Not Used\n");
                } else if (LAZYBIOS_FIELD_STATUS(type22, sbds_serial_number) != LAZYBIOS_FIELD_PRESENT) {
                    printf("SBDS Serial Number: Not Present\n");
                } else {
                    printf("SBDS Serial Number: 0x%04hX\n", type22->sbds_serial_number);
                }
                if (type22->manufacture_date) {
                    printf("SBDS Manufacture Date: Not Used\n");
                } else if (LAZYBIOS_FIELD_STATUS(type22, sbds_manufacture_date) != LAZYBIOS_FIELD_PRESENT) {
                    printf("SBDS Manufacture Date: Not Present\n");
                } else {
                    char buf[LAZYBIOS_DECODER_BUF_SIZE];
                    lazybiosType22SBDSManufactureDateStr(type22->sbds_manufacture_date, buf, sizeof(buf));
                    printf("SBDS Manufacture Date: %s\n", buf);
                }
                if (type22->device_chemistry != 0x02) {
                    printf("SBDS Device Chemistry: Not Used\n");
                } else if (LAZYBIOS_FIELD_STATUS(type22, sbds_device_chemistry) != LAZYBIOS_FIELD_PRESENT) {
                    printf("SBDS Device Chemistry: Not Present\n");
                } else {
                    printf("SBDS Device Chemistry: %s\n", type22->sbds_device_chemistry ? type22->sbds_device_chemistry : "Not Specified");
                }
                if (LAZYBIOS_FIELD_STATUS(type22, design_capacity_multiplier) != LAZYBIOS_FIELD_PRESENT) {
                    printf("Design Capacity Multiplier: Not Present\n");
                } else {
                    printf("Design Capacity Multiplier: %hhu\n", type22->design_capacity_multiplier);
                }
                if (LAZYBIOS_FIELD_STATUS(type22, oem_specific) != LAZYBIOS_FIELD_PRESENT) {
                    printf("OEM-specific Information: Not Present\n");
                } else {
                    printf("OEM-specific Information: 0x%08X\n", type22->oem_specific);
                }
            } else if (!compact_output) {
                printf("SBDS Serial Number: [SMBIOS 2.2 required]\n");
                printf("SBDS Manufacture Date: [SMBIOS 2.2 required]\n");
                printf("SBDS Device Chemistry: [SMBIOS 2.2 required]\n");
                printf("Design Capacity Multiplier: [SMBIOS 2.2 required]\n");
                printf("OEM-specific Information: [SMBIOS 2.2 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Portable Battery information\n\n");
    }
}

static void printType23(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM RESET ===\n");
    if (!ctx->Type23) ctx->Type23 = lazybiosGetType23(ctx->Type23, &ctx->type23_count, ctx->DMIData);
    if (ctx->Type23 && ctx->type23_count > 0) {
        for (size_t i = 0; i < ctx->type23_count; i++) {
            lazybiosType23_t *type23 = &ctx->Type23[i];
            if (ctx->type23_count > 1) { printf("--- System Reset %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type23, capabilities) != LAZYBIOS_FIELD_PRESENT) {
                printf("Capabilities: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType23CapabilitiesStr(type23->capabilities, buf, sizeof(buf));
                printf("Capabilities: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type23, reset_count) != LAZYBIOS_FIELD_PRESENT) {
                printf("Reset Count: Not Present\n");
            } else if (type23->reset_count == 0xFFFF) {
                printf("Reset Count: Unknown\n");
            } else {
                printf("Reset Count: %hu\n", type23->reset_count);
            }
            if (LAZYBIOS_FIELD_STATUS(type23, reset_limit) != LAZYBIOS_FIELD_PRESENT) {
                printf("Reset Limit: Not Present\n");
            } else if (type23->reset_limit == 0xFFFF) {
                printf("Reset Limit: Unknown\n");
            } else {
                printf("Reset Limit: %hu\n", type23->reset_limit);
            }
            if (LAZYBIOS_FIELD_STATUS(type23, timer_interval) != LAZYBIOS_FIELD_PRESENT) {
                printf("Timer Interval: Not Present\n");
            } else if (type23->timer_interval == 0xFFFF) {
                printf("Timer Interval: Unknown\n");
            } else {
                printf("Timer Interval: %hu minutes\n", type23->timer_interval);
            }
            if (LAZYBIOS_FIELD_STATUS(type23, timeout) != LAZYBIOS_FIELD_PRESENT) {
                printf("Timeout: Not Present\n");
            } else if (type23->timeout == 0xFFFF) {
                printf("Timeout: Unknown\n");
            } else {
                printf("Timeout: %hu minutes\n", type23->timeout);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Reset information\n\n");
    }
}

static void printType24(lazybiosCTX_t *ctx) {
    printf("=== HARDWARE SECURITY ===\n");
    if (!ctx->Type24) ctx->Type24 = lazybiosGetType24(ctx->Type24, &ctx->type24_count, ctx->DMIData);
    if (ctx->Type24 && ctx->type24_count > 0) {
        for (size_t i = 0; i < ctx->type24_count; i++) {
            lazybiosType24_t *type24 = &ctx->Type24[i];
            if (ctx->type24_count > 1) { printf("--- Hardware Security %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type24, hardware_security_settings) != LAZYBIOS_FIELD_PRESENT) {
                printf("Power-on Password Status: Not Present\n");
                printf("Keyboard Password Status: Not Present\n");
                printf("Administrator Password Status: Not Present\n");
                printf("Front Panel Reset Status: Not Present\n");
            } else {
                printf("Power-on Password Status: %s\n", lazybiosType24PowerOnPasswordStatusStr(type24->hardware_security_settings));
                printf("Keyboard Password Status: %s\n", lazybiosType24KeyboardPasswordStatusStr(type24->hardware_security_settings));
                printf("Administrator Password Status: %s\n", lazybiosType24AdministratorPasswordStatusStr(type24->hardware_security_settings));
                printf("Front Panel Reset Status: %s\n", lazybiosType24FrontPanelResetStatusStr(type24->hardware_security_settings));
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Hardware Security information\n\n");
    }
}

static void printType25(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM POWER CONTROLS ===\n");
    if (!ctx->Type25) ctx->Type25 = lazybiosGetType25(ctx->Type25, &ctx->type25_count, ctx->DMIData);
    if (ctx->Type25 && ctx->type25_count > 0) {
        for (size_t i = 0; i < ctx->type25_count; i++) {
            lazybiosType25_t *type25 = &ctx->Type25[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type25_count > 1) { printf("--- System Power Controls %zu ---\n", i + 1); }
            lazybiosType25NextScheduledPowerOnStr(type25, buf, sizeof(buf));
            printf("Next Scheduled Power-on: %s\n\n", buf);
        }
    } else {
        printf("Failed to get System Power Controls information\n\n");
    }
}

static void printType26(lazybiosCTX_t *ctx) {
    printf("=== VOLTAGE PROBE ===\n");
    if (!ctx->Type26) ctx->Type26 = lazybiosGetType26(ctx->Type26, &ctx->type26_count, ctx->DMIData);
    if (ctx->Type26 && ctx->type26_count > 0) {
        for (size_t i = 0; i < ctx->type26_count; i++) {
            lazybiosType26_t *type26 = &ctx->Type26[i];
            if (ctx->type26_count > 1) { printf("--- Voltage Probe %zu ---\n", i + 1); }
            printf("Description: %s\n", type26->description ? type26->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type26, location_and_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Location: Not Present\n");
                printf("Status: Not Present\n");
            } else {
                printf("Location: %s\n", lazybiosType26LocationStr(type26->location_and_status));
                printf("Status: %s\n", lazybiosType26StatusStr(type26->location_and_status));
            }
            if (LAZYBIOS_FIELD_STATUS(type26, maximum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Value: Not Present\n");
            } else if (type26->maximum_value == 0x8000) {
                printf("Maximum Value: Unknown\n");
            } else {
                printf("Maximum Value: %hu mV\n", type26->maximum_value);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, minimum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Minimum Value: Not Present\n");
            } else if (type26->minimum_value == 0x8000) {
                printf("Minimum Value: Unknown\n");
            } else {
                printf("Minimum Value: %hu mV\n", type26->minimum_value);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, resolution) != LAZYBIOS_FIELD_PRESENT) {
                printf("Resolution: Not Present\n");
            } else if (type26->resolution == 0x8000) {
                printf("Resolution: Unknown\n");
            } else {
                printf("Resolution: %hu.%hu mV\n", type26->resolution / 10, type26->resolution % 10);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, tolerance) != LAZYBIOS_FIELD_PRESENT) {
                printf("Tolerance: Not Present\n");
            } else if (type26->tolerance == 0x8000) {
                printf("Tolerance: Unknown\n");
            } else {
                printf("Tolerance: +/- %hu mV\n", type26->tolerance);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, accuracy) != LAZYBIOS_FIELD_PRESENT) {
                printf("Accuracy: Not Present\n");
            } else if (type26->accuracy == 0x8000) {
                printf("Accuracy: Unknown\n");
            } else {
                printf("Accuracy: +/- %hu.%02hu%%\n", type26->accuracy / 100, type26->accuracy % 100);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                printf("OEM-defined Information: Not Present\n");
            } else {
                printf("OEM-defined Information: 0x%08X\n", type26->oem_defined);
            }
            if (LAZYBIOS_FIELD_STATUS(type26, nominal_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Nominal Value: Not Present\n");
            } else if (type26->nominal_value == 0x8000) {
                printf("Nominal Value: Unknown\n");
            } else {
                printf("Nominal Value: %hu mV\n", type26->nominal_value);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Voltage Probe information\n\n");
    }
}

static void printType27(lazybiosCTX_t *ctx) {
    printf("=== COOLING DEVICE ===\n");
    if (!ctx->Type27) ctx->Type27 = lazybiosGetType27(ctx->Type27, &ctx->type27_count, ctx->DMIData);
    if (ctx->Type27 && ctx->type27_count > 0) {
        for (size_t i = 0; i < ctx->type27_count; i++) {
            lazybiosType27_t *type27 = &ctx->Type27[i];
            if (ctx->type27_count > 1) { printf("--- Cooling Device %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type27, temperature_probe_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Temperature Probe Handle: Not Present\n");
            } else {
                printf("Temperature Probe Handle: 0x%04hX\n", type27->temperature_probe_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type27, device_type_and_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Type: Not Present\n");
                printf("Status: Not Present\n");
            } else {
                printf("Device Type: %s\n", lazybiosType27DeviceTypeStr(type27->device_type_and_status));
                printf("Status: %s\n", lazybiosType27StatusStr(type27->device_type_and_status));
            }
            if (LAZYBIOS_FIELD_STATUS(type27, cooling_unit_group) != LAZYBIOS_FIELD_PRESENT) {
                printf("Cooling Unit Group: Not Present\n");
            } else if (type27->cooling_unit_group == 0) {
                printf("Cooling Unit Group: None\n");
            } else {
                printf("Cooling Unit Group: %hhu\n", type27->cooling_unit_group);
            }
            if (LAZYBIOS_FIELD_STATUS(type27, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                printf("OEM-defined Information: Not Present\n");
            } else {
                printf("OEM-defined Information: 0x%08X\n", type27->oem_defined);
            }
            if (LAZYBIOS_FIELD_STATUS(type27, nominal_speed) != LAZYBIOS_FIELD_PRESENT) {
                printf("Nominal Speed: Not Present\n");
            } else if (type27->nominal_speed == 0x8000) {
                printf("Nominal Speed: Unknown or Non-rotating\n");
            } else {
                printf("Nominal Speed: %hu rpm\n", type27->nominal_speed);
            }
            if (lazybiosIsVersionPlus(ctx->DMIData, 2, 7)) {
                printf("Description: %s\n", type27->description ? type27->description : "Not Present");
            } else if (!compact_output) {
                printf("Description: [SMBIOS 2.7 required]\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Cooling Device information\n\n");
    }
}

static void printType28(lazybiosCTX_t *ctx) {
    printf("=== TEMPERATURE PROBE ===\n");
    if (!ctx->Type28) ctx->Type28 = lazybiosGetType28(ctx->Type28, &ctx->type28_count, ctx->DMIData);
    if (ctx->Type28 && ctx->type28_count > 0) {
        for (size_t i = 0; i < ctx->type28_count; i++) {
            lazybiosType28_t *type28 = &ctx->Type28[i];
            if (ctx->type28_count > 1) { printf("--- Temperature Probe %zu ---\n", i + 1); }
            printf("Description: %s\n", type28->description ? type28->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type28, location_and_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Location: Not Present\n");
                printf("Status: Not Present\n");
            } else {
                printf("Location: %s\n", lazybiosType28LocationStr(type28->location_and_status));
                printf("Status: %s\n", lazybiosType28StatusStr(type28->location_and_status));
            }
            if (LAZYBIOS_FIELD_STATUS(type28, maximum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Value: Not Present\n");
            } else if (type28->maximum_value == 0x8000) {
                printf("Maximum Value: Unknown\n");
            } else {
                printf("Maximum Value: %hu.%hu degrees C\n", type28->maximum_value / 10, type28->maximum_value % 10);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, minimum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Minimum Value: Not Present\n");
            } else if (type28->minimum_value == INT16_MIN) {
                printf("Minimum Value: Unknown\n");
            } else {
                printf("Minimum Value: %.1f degrees C\n", (double)type28->minimum_value / 10.0);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, resolution) != LAZYBIOS_FIELD_PRESENT) {
                printf("Resolution: Not Present\n");
            } else if (type28->resolution == 0x8000) {
                printf("Resolution: Unknown\n");
            } else {
                printf("Resolution: %hu.%03hu degrees C\n", type28->resolution / 1000, type28->resolution % 1000);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, tolerance) != LAZYBIOS_FIELD_PRESENT) {
                printf("Tolerance: Not Present\n");
            } else if (type28->tolerance == 0x8000) {
                printf("Tolerance: Unknown\n");
            } else {
                printf("Tolerance: +/- %hu.%hu degrees C\n", type28->tolerance / 10, type28->tolerance % 10);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, accuracy) != LAZYBIOS_FIELD_PRESENT) {
                printf("Accuracy: Not Present\n");
            } else if (type28->accuracy == 0x8000) {
                printf("Accuracy: Unknown\n");
            } else {
                printf("Accuracy: +/- %hu.%02hu%%\n", type28->accuracy / 100, type28->accuracy % 100);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                printf("OEM-defined Information: Not Present\n");
            } else {
                printf("OEM-defined Information: 0x%08X\n", type28->oem_defined);
            }
            if (LAZYBIOS_FIELD_STATUS(type28, nominal_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Nominal Value: Not Present\n");
            } else if (type28->nominal_value == 0x8000) {
                printf("Nominal Value: Unknown\n");
            } else {
                printf("Nominal Value: %hu.%hu degrees C\n", type28->nominal_value / 10, type28->nominal_value % 10);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Temperature Probe information\n\n");
    }
}

static void printType29(lazybiosCTX_t *ctx) {
    printf("=== ELECTRICAL CURRENT PROBE ===\n");
    if (!ctx->Type29) ctx->Type29 = lazybiosGetType29(ctx->Type29, &ctx->type29_count, ctx->DMIData);
    if (ctx->Type29 && ctx->type29_count > 0) {
        for (size_t i = 0; i < ctx->type29_count; i++) {
            lazybiosType29_t *type29 = &ctx->Type29[i];
            if (ctx->type29_count > 1) { printf("--- Electrical Current Probe %zu ---\n", i + 1); }
            printf("Description: %s\n", type29->description ? type29->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type29, location_and_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Location: Not Present\n");
                printf("Status: Not Present\n");
            } else {
                printf("Location: %s\n", lazybiosType29LocationStr(type29->location_and_status));
                printf("Status: %s\n", lazybiosType29StatusStr(type29->location_and_status));
            }
            if (LAZYBIOS_FIELD_STATUS(type29, maximum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Value: Not Present\n");
            } else if (type29->maximum_value == 0x8000) {
                printf("Maximum Value: Unknown\n");
            } else {
                printf("Maximum Value: %hu mA\n", type29->maximum_value);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, minimum_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Minimum Value: Not Present\n");
            } else if (type29->minimum_value == 0x8000) {
                printf("Minimum Value: Unknown\n");
            } else {
                printf("Minimum Value: %hu mA\n", type29->minimum_value);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, resolution) != LAZYBIOS_FIELD_PRESENT) {
                printf("Resolution: Not Present\n");
            } else if (type29->resolution == 0x8000) {
                printf("Resolution: Unknown\n");
            } else {
                printf("Resolution: %hu.%hu mA\n", type29->resolution / 10, type29->resolution % 10);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, tolerance) != LAZYBIOS_FIELD_PRESENT) {
                printf("Tolerance: Not Present\n");
            } else if (type29->tolerance == 0x8000) {
                printf("Tolerance: Unknown\n");
            } else {
                printf("Tolerance: +/- %hu mA\n", type29->tolerance);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, accuracy) != LAZYBIOS_FIELD_PRESENT) {
                printf("Accuracy: Not Present\n");
            } else if (type29->accuracy == 0x8000) {
                printf("Accuracy: Unknown\n");
            } else {
                printf("Accuracy: +/- %hu.%02hu%%\n", type29->accuracy / 100, type29->accuracy % 100);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                printf("OEM-defined Information: Not Present\n");
            } else {
                printf("OEM-defined Information: 0x%08X\n", type29->oem_defined);
            }
            if (LAZYBIOS_FIELD_STATUS(type29, nominal_value) != LAZYBIOS_FIELD_PRESENT) {
                printf("Nominal Value: Not Present\n");
            } else if (type29->nominal_value == 0x8000) {
                printf("Nominal Value: Unknown\n");
            } else {
                printf("Nominal Value: %hu mA\n", type29->nominal_value);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Electrical Current Probe information\n\n");
    }
}

static void printType30(lazybiosCTX_t *ctx) {
    printf("=== OUT-OF-BAND REMOTE ACCESS ===\n");
    if (!ctx->Type30) ctx->Type30 = lazybiosGetType30(ctx->Type30, &ctx->type30_count, ctx->DMIData);
    if (ctx->Type30 && ctx->type30_count > 0) {
        for (size_t i = 0; i < ctx->type30_count; i++) {
            lazybiosType30_t *type30 = &ctx->Type30[i];
            if (ctx->type30_count > 1) { printf("--- Out-of-Band Remote Access %zu ---\n", i + 1); }
            printf("Manufacturer Name: %s\n", type30->manufacturer_name ? type30->manufacturer_name : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type30, connections) != LAZYBIOS_FIELD_PRESENT) {
                printf("Inbound Connection: Not Present\n");
                printf("Outbound Connection: Not Present\n");
            } else {
                printf("Inbound Connection: %s\n", lazybiosType30InboundConnectionStr(type30->connections));
                printf("Outbound Connection: %s\n", lazybiosType30OutboundConnectionStr(type30->connections));
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Out-of-Band Remote Access information\n\n");
    }
}

static void printType31(lazybiosCTX_t *ctx) {
    printf("=== BOOT INTEGRITY SERVICES ENTRY POINT ===\n");
    if (!ctx->Type31) ctx->Type31 = lazybiosGetType31(ctx->Type31, &ctx->type31_count, ctx->DMIData);
    if (ctx->Type31 && ctx->type31_count > 0) {
        for (size_t i = 0; i < ctx->type31_count; i++) {
            lazybiosType31_t *type31 = &ctx->Type31[i];
            if (ctx->type31_count > 1) { printf("--- Boot Integrity Services Entry Point %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type31, checksum) != LAZYBIOS_FIELD_PRESENT) {
                printf("Checksum: Not Present\n");
            } else {
                printf("Checksum: 0x%02X\n", type31->checksum);
            }
            if (LAZYBIOS_FIELD_STATUS(type31, checksum_valid) != LAZYBIOS_FIELD_PRESENT) {
                printf("Structure Checksum: Not Available\n");
            } else {
                printf("Structure Checksum: %s\n", type31->checksum_valid ? "Valid" : "Invalid");
            }
            if (LAZYBIOS_FIELD_STATUS(type31, bis_entry_point_16) != LAZYBIOS_FIELD_PRESENT) {
                printf("16-bit Entry Point: Not Present\n");
            } else {
                printf("16-bit Entry Point: 0x%08X\n", type31->bis_entry_point_16);
            }
            if (LAZYBIOS_FIELD_STATUS(type31, bis_entry_point_32) != LAZYBIOS_FIELD_PRESENT) {
                printf("32-bit Entry Point: Not Present\n");
            } else {
                printf("32-bit Entry Point: 0x%08X\n", type31->bis_entry_point_32);
            }
            if (LAZYBIOS_FIELD_STATUS(type31, reserved_1) != LAZYBIOS_FIELD_PRESENT || LAZYBIOS_FIELD_STATUS(type31, reserved_2) != LAZYBIOS_FIELD_PRESENT ||
                LAZYBIOS_FIELD_STATUS(type31, reserved_3) != LAZYBIOS_FIELD_PRESENT || LAZYBIOS_FIELD_STATUS(type31, reserved_4) != LAZYBIOS_FIELD_PRESENT) {
                printf("Reserved Fields: Not Present\n");
            } else {
                printf("Reserved Fields: 0x%02X, 0x%04hX, 0x%016llX, 0x%08X\n", type31->reserved_1, type31->reserved_2, (unsigned long long)type31->reserved_3,
                       type31->reserved_4);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Boot Integrity Services Entry Point information\n\n");
    }
}

static void printType32(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM BOOT INFORMATION ===\n");
    if (!ctx->Type32) ctx->Type32 = lazybiosGetType32(ctx->Type32, &ctx->type32_count, ctx->DMIData);
    if (ctx->Type32 && ctx->type32_count > 0) {
        for (size_t i = 0; i < ctx->type32_count; i++) {
            lazybiosType32_t *type32 = &ctx->Type32[i];
            if (ctx->type32_count > 1) { printf("--- System Boot Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type32, reserved) != LAZYBIOS_FIELD_PRESENT) {
                printf("Reserved Bytes: Not Present\n");
            } else {
                printf("Reserved Bytes:");
                for (size_t j = 0; j < sizeof(type32->reserved); j++) { printf(" %02X", type32->reserved[j]); }
                printf("\n");
            }
            if (LAZYBIOS_FIELD_STATUS(type32, boot_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Boot Status: Not Present\n");
            } else {
                printf("Boot Status: %s (%hhu)\n", lazybiosType32BootStatusStr(type32->boot_status), type32->boot_status);
            }
            if (LAZYBIOS_FIELD_STATUS(type32, additional_data) != LAZYBIOS_FIELD_PRESENT) {
                printf("Additional Data: Not Present\n");
            } else if (type32->additional_data_size == 0) {
                printf("Additional Data: None\n");
            } else {
                printf("Additional Data:");
                for (size_t j = 0; j < type32->additional_data_size; j++) { printf(" %02X", type32->additional_data[j]); }
                printf("\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Boot Information\n\n");
    }
}

static void printType33(lazybiosCTX_t *ctx) {
    printf("=== 64-BIT MEMORY ERROR INFORMATION ===\n");
    if (!ctx->Type33) ctx->Type33 = lazybiosGetType33(ctx->Type33, &ctx->type33_count, ctx->DMIData);
    if (ctx->Type33 && ctx->type33_count > 0) {
        for (size_t i = 0; i < ctx->type33_count; i++) {
            lazybiosType33_t *type33 = &ctx->Type33[i];
            if (ctx->type33_count > 1) { printf("--- 64-Bit Memory Error Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type33, error_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Type: Not Present\n");
            } else {
                printf("Error Type: %s\n", lazybiosType33ErrorTypeStr(type33->error_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type33, error_granularity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Granularity: Not Present\n");
            } else {
                printf("Error Granularity: %s\n", lazybiosType33ErrorGranularityStr(type33->error_granularity));
            }
            if (LAZYBIOS_FIELD_STATUS(type33, error_operation) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Operation: Not Present\n");
            } else {
                printf("Error Operation: %s\n", lazybiosType33ErrorOperationStr(type33->error_operation));
            }
            if (LAZYBIOS_FIELD_STATUS(type33, vendor_syndrome) != LAZYBIOS_FIELD_PRESENT) {
                printf("Vendor Syndrome: Not Present\n");
            } else if (type33->vendor_syndrome == 0) {
                printf("Vendor Syndrome: Unknown\n");
            } else {
                printf("Vendor Syndrome: 0x%08X\n", type33->vendor_syndrome);
            }
            if (LAZYBIOS_FIELD_STATUS(type33, memory_array_error_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Array Error Address: Not Present\n");
            } else if (type33->memory_array_error_address == 0x8000000000000000ULL) {
                printf("Memory Array Error Address: Unknown\n");
            } else {
                printf("Memory Array Error Address: 0x%016llX\n", (unsigned long long)type33->memory_array_error_address);
            }
            if (LAZYBIOS_FIELD_STATUS(type33, device_error_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Error Address: Not Present\n");
            } else if (type33->device_error_address == 0x8000000000000000ULL) {
                printf("Device Error Address: Unknown\n");
            } else {
                printf("Device Error Address: 0x%016llX\n", (unsigned long long)type33->device_error_address);
            }
            if (LAZYBIOS_FIELD_STATUS(type33, error_resolution) != LAZYBIOS_FIELD_PRESENT) {
                printf("Error Resolution: Not Present\n");
            } else if (type33->error_resolution == 0x80000000U) {
                printf("Error Resolution: Unknown\n");
            } else {
                printf("Error Resolution: %u bytes\n", type33->error_resolution);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get 64-Bit Memory Error information\n\n");
    }
}

static void printType34(lazybiosCTX_t *ctx) {
    printf("=== MANAGEMENT DEVICE ===\n");
    if (!ctx->Type34) ctx->Type34 = lazybiosGetType34(ctx->Type34, &ctx->type34_count, ctx->DMIData);
    if (ctx->Type34 && ctx->type34_count > 0) {
        for (size_t i = 0; i < ctx->type34_count; i++) {
            lazybiosType34_t *type34 = &ctx->Type34[i];
            if (ctx->type34_count > 1) { printf("--- Management Device %zu ---\n", i + 1); }
            printf("Description: %s\n", type34->description ? type34->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type34, device_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Type: Not Present\n");
            } else {
                printf("Device Type: %s\n", lazybiosType34DeviceTypeStr(type34->device_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type34, address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Address: Not Present\n");
            } else {
                printf("Address: 0x%08X\n", type34->address);
            }
            if (LAZYBIOS_FIELD_STATUS(type34, address_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Address Type: Not Present\n");
            } else {
                printf("Address Type: %s\n", lazybiosType34AddressTypeStr(type34->address_type));
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Management Device information\n\n");
    }
}

static void printType35(lazybiosCTX_t *ctx) {
    printf("=== MANAGEMENT DEVICE COMPONENT ===\n");
    if (!ctx->Type35) ctx->Type35 = lazybiosGetType35(ctx->Type35, &ctx->type35_count, ctx->DMIData);
    if (ctx->Type35 && ctx->type35_count > 0) {
        for (size_t i = 0; i < ctx->type35_count; i++) {
            lazybiosType35_t *type35 = &ctx->Type35[i];
            if (ctx->type35_count > 1) { printf("--- Management Device Component %zu ---\n", i + 1); }
            printf("Description: %s\n", type35->description ? type35->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type35, management_device_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Management Device Handle: Not Present\n");
            } else {
                printf("Management Device Handle: 0x%04hX\n", type35->management_device_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type35, component_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Component Handle: Not Present\n");
            } else {
                printf("Component Handle: 0x%04hX\n", type35->component_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type35, threshold_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Threshold Handle: Not Present\n");
            } else {
                printf("Threshold Handle: 0x%04hX\n", type35->threshold_handle);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Management Device Component information\n\n");
    }
}

static void printType36(lazybiosCTX_t *ctx) {
    printf("=== MANAGEMENT DEVICE THRESHOLD DATA ===\n");
    if (!ctx->Type36) ctx->Type36 = lazybiosGetType36(ctx->Type36, &ctx->type36_count, ctx->DMIData);
    if (ctx->Type36 && ctx->type36_count > 0) {
        for (size_t i = 0; i < ctx->type36_count; i++) {
            lazybiosType36_t *type36 = &ctx->Type36[i];
            if (ctx->type36_count > 1) { printf("--- Management Device Threshold Data %zu ---\n", i + 1); }
            if (type36->lower_threshold_non_critical == 0x8000) {
                printf("Lower Non-critical Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, lower_threshold_non_critical) != LAZYBIOS_FIELD_PRESENT) {
                printf("Lower Non-critical Threshold: Not Present\n");
            } else {
                printf("Lower Non-critical Threshold: %hu\n", type36->lower_threshold_non_critical);
            }
            if (type36->upper_threshold_non_critical == 0x8000) {
                printf("Upper Non-critical Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, upper_threshold_non_critical) != LAZYBIOS_FIELD_PRESENT) {
                printf("Upper Non-critical Threshold: Not Present\n");
            } else {
                printf("Upper Non-critical Threshold: %hu\n", type36->upper_threshold_non_critical);
            }
            if (type36->lower_threshold_critical == 0x8000) {
                printf("Lower Critical Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, lower_threshold_critical) != LAZYBIOS_FIELD_PRESENT) {
                printf("Lower Critical Threshold: Not Present\n");
            } else {
                printf("Lower Critical Threshold: %hu\n", type36->lower_threshold_critical);
            }
            if (type36->upper_threshold_critical == 0x8000) {
                printf("Upper Critical Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, upper_threshold_critical) != LAZYBIOS_FIELD_PRESENT) {
                printf("Upper Critical Threshold: Not Present\n");
            } else {
                printf("Upper Critical Threshold: %hu\n", type36->upper_threshold_critical);
            }
            if (type36->lower_threshold_non_recoverable == 0x8000) {
                printf("Lower Non-recoverable Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, lower_threshold_non_recoverable) != LAZYBIOS_FIELD_PRESENT) {
                printf("Lower Non-recoverable Threshold: Not Present\n");
            } else {
                printf("Lower Non-recoverable Threshold: %hu\n", type36->lower_threshold_non_recoverable);
            }
            if (type36->upper_threshold_non_recoverable == 0x8000) {
                printf("Upper Non-recoverable Threshold: Unavailable\n");
            } else if (LAZYBIOS_FIELD_STATUS(type36, upper_threshold_non_recoverable) != LAZYBIOS_FIELD_PRESENT) {
                printf("Upper Non-recoverable Threshold: Not Present\n");
            } else {
                printf("Upper Non-recoverable Threshold: %hu\n", type36->upper_threshold_non_recoverable);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Management Device Threshold Data information\n\n");
    }
}

static void printType37(lazybiosCTX_t *ctx) {
    printf("=== MEMORY CHANNEL ===\n");
    if (!ctx->Type37) ctx->Type37 = lazybiosGetType37(ctx->Type37, &ctx->type37_count, ctx->DMIData);
    if (ctx->Type37 && ctx->type37_count > 0) {
        for (size_t i = 0; i < ctx->type37_count; i++) {
            lazybiosType37_t *type37 = &ctx->Type37[i];
            if (ctx->type37_count > 1) { printf("--- Memory Channel %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type37, channel_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Channel Type: Not Present\n");
            } else {
                printf("Channel Type: %s\n", lazybiosType37ChannelTypeStr(type37->channel_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type37, maximum_channel_load) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Channel Load: Not Present\n");
            } else {
                printf("Maximum Channel Load: %hhu\n", type37->maximum_channel_load);
            }
            if (LAZYBIOS_FIELD_STATUS(type37, memory_device_count) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Device Count: Not Present\n");
            } else {
                printf("Memory Device Count: %hhu\n", type37->memory_device_count);
            }
            if (LAZYBIOS_FIELD_STATUS(type37, memory_devices) != LAZYBIOS_FIELD_PRESENT) {
                printf("Memory Devices: Not Present\n");
            } else {
                for (size_t j = 0; j < type37->memory_device_count; j++) {
                    lazybiosType37MemoryDevice_t *device = &type37->memory_devices[j];
                    printf("Memory Device %zu Load: %hhu\n", j + 1, device->load);
                    printf("Memory Device %zu Handle: 0x%04hX\n", j + 1, device->handle);
                }
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Memory Channel information\n\n");
    }
}

static void printType38(lazybiosCTX_t *ctx) {
    printf("=== IPMI DEVICE INFORMATION ===\n");
    if (!ctx->Type38) ctx->Type38 = lazybiosGetType38(ctx->Type38, &ctx->type38_count, ctx->DMIData);
    if (ctx->Type38 && ctx->type38_count > 0) {
        for (size_t i = 0; i < ctx->type38_count; i++) {
            lazybiosType38_t *type38 = &ctx->Type38[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type38_count > 1) { printf("--- IPMI Device Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type38, interface_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interface Type: Not Present\n");
            } else {
                printf("Interface Type: %s\n", lazybiosType38InterfaceTypeStr(type38->interface_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type38, ipmi_specification_revision) != LAZYBIOS_FIELD_PRESENT) {
                printf("IPMI Specification Revision: Not Present\n");
            } else {
                lazybiosType38SpecificationRevisionStr(type38->ipmi_specification_revision, buf, sizeof(buf));
                printf("IPMI Specification Revision: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type38, i2c_target_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("I2C Target Address: Not Present\n");
            } else {
                printf("I2C Target Address: 0x%02hhX\n", type38->i2c_target_address);
            }
            if (type38->nv_storage_device_address == 0xFF) {
                printf("NV Storage Device Address: No Storage Device\n");
            } else if (LAZYBIOS_FIELD_STATUS(type38, nv_storage_device_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("NV Storage Device Address: Not Present\n");
            } else {
                printf("NV Storage Device Address: 0x%02hhX\n", type38->nv_storage_device_address);
            }
            if (LAZYBIOS_FIELD_STATUS(type38, base_address) != LAZYBIOS_FIELD_PRESENT) {
                printf("Base Address: Not Present\n");
                printf("Base Address Type: Not Present\n");
            } else {
                printf("Base Address Type: %s\n", lazybiosType38BaseAddressTypeStr(type38->base_address));
                if (LAZYBIOS_FIELD_STATUS(type38, base_address_modifier_interrupt_info) == LAZYBIOS_FIELD_PRESENT) {
                    printf("Base Address: 0x%016llX\n",
                           (unsigned long long)lazybiosType38BaseAddressValue(type38->base_address, type38->base_address_modifier_interrupt_info));
                } else {
                    printf("Base Address: 0x%016llX (raw)\n", (unsigned long long)type38->base_address);
                }
            }
            if (LAZYBIOS_FIELD_STATUS(type38, base_address_modifier_interrupt_info) != LAZYBIOS_FIELD_PRESENT) {
                printf("Register Spacing: Not Present\n");
                printf("Interrupt Information: Not Present\n");
            } else {
                printf("Register Spacing: %s\n", lazybiosType38RegisterSpacingStr(type38->base_address_modifier_interrupt_info));
                lazybiosType38InterruptInfoStr(type38->base_address_modifier_interrupt_info, buf, sizeof(buf));
                printf("Interrupt Information: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type38, interrupt_number) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interrupt Number: Not Present\n");
            } else if (type38->interrupt_number == 0) {
                printf("Interrupt Number: Unspecified/Unsupported\n");
            } else {
                printf("Interrupt Number: %hhu\n", type38->interrupt_number);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get IPMI Device information\n\n");
    }
}

static void printType39(lazybiosCTX_t *ctx) {
    printf("=== SYSTEM POWER SUPPLY ===\n");
    if (!ctx->Type39) ctx->Type39 = lazybiosGetType39(ctx->Type39, &ctx->type39_count, ctx->DMIData);
    if (ctx->Type39 && ctx->type39_count > 0) {
        for (size_t i = 0; i < ctx->type39_count; i++) {
            lazybiosType39_t *type39 = &ctx->Type39[i];
            if (ctx->type39_count > 1) { printf("--- System Power Supply %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type39, power_unit_group) != LAZYBIOS_FIELD_PRESENT) {
                printf("Power Unit Group: Not Present\n");
            } else if (type39->power_unit_group == 0) {
                printf("Power Unit Group: 0 (Not Redundant)\n");
            } else {
                printf("Power Unit Group: %hhu\n", type39->power_unit_group);
            }
            printf("Location: %s\n", type39->location ? type39->location : "Not Present");
            printf("Device Name: %s\n", type39->device_name ? type39->device_name : "Not Present");
            printf("Manufacturer: %s\n", type39->manufacturer ? type39->manufacturer : "Not Present");
            printf("Serial Number: %s\n", type39->serial_number ? type39->serial_number : "Not Present");
            printf("Asset Tag Number: %s\n", type39->asset_tag_number ? type39->asset_tag_number : "Not Present");
            printf("Model Part Number: %s\n", type39->model_part_number ? type39->model_part_number : "Not Present");
            printf("Revision Level: %s\n", type39->revision_level ? type39->revision_level : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type39, max_power_capacity) != LAZYBIOS_FIELD_PRESENT) {
                printf("Maximum Power Capacity: Not Present\n");
            } else if (type39->max_power_capacity == 0x8000) {
                printf("Maximum Power Capacity: Unknown\n");
            } else {
                printf("Maximum Power Capacity: %hu W\n", type39->max_power_capacity);
            }
            if (LAZYBIOS_FIELD_STATUS(type39, power_supply_characteristics) != LAZYBIOS_FIELD_PRESENT) {
                printf("Power Supply Type: Not Present\n");
                printf("Power Supply Status: Not Present\n");
                printf("Input Voltage Range Switching: Not Present\n");
                printf("Power Supply Flags: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                printf("Power Supply Type: %s\n", lazybiosType39PowerSupplyTypeStr(type39->power_supply_characteristics));
                printf("Power Supply Status: %s\n", lazybiosType39StatusStr(type39->power_supply_characteristics));
                printf("Input Voltage Range Switching: %s\n", lazybiosType39InputVoltageRangeSwitchingStr(type39->power_supply_characteristics));
                lazybiosType39CharacteristicsFlagsStr(type39->power_supply_characteristics, buf, sizeof(buf));
                printf("Power Supply Flags: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type39, input_voltage_probe_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Input Voltage Probe Handle: Not Present\n");
            } else {
                printf("Input Voltage Probe Handle: 0x%04hX\n", type39->input_voltage_probe_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type39, cooling_device_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Cooling Device Handle: Not Present\n");
            } else {
                printf("Cooling Device Handle: 0x%04hX\n", type39->cooling_device_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type39, input_current_probe_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Input Current Probe Handle: Not Present\n");
            } else {
                printf("Input Current Probe Handle: 0x%04hX\n", type39->input_current_probe_handle);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get System Power Supply information\n\n");
    }
}

static void printType40(lazybiosCTX_t *ctx) {
    printf("=== ADDITIONAL INFORMATION ===\n");
    if (!ctx->Type40) ctx->Type40 = lazybiosGetType40(ctx->Type40, &ctx->type40_count, ctx->DMIData);
    if (ctx->Type40 && ctx->type40_count > 0) {
        for (size_t i = 0; i < ctx->type40_count; i++) {
            lazybiosType40_t *type40 = &ctx->Type40[i];
            if (ctx->type40_count > 1) { printf("--- Additional Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type40, additional_information_entry_count) != LAZYBIOS_FIELD_PRESENT) {
                printf("Additional Information Entry Count: Not Present\n");
            } else {
                printf("Additional Information Entry Count: %hhu\n", type40->additional_information_entry_count);
            }
            if (LAZYBIOS_FIELD_STATUS(type40, additional_information_entries) != LAZYBIOS_FIELD_PRESENT) {
                printf("Additional Information Entries: Not Present\n");
            } else {
                for (size_t j = 0; j < type40->additional_information_entry_count; j++) {
                    lazybiosType40Entry_t *entry = &type40->additional_information_entries[j];
                    printf("--- Entry %zu ---\n", j + 1);
                    printf("Entry Length: %hhu bytes\n", entry->entry_length);
                    printf("Referenced Handle: 0x%04hX\n", entry->referenced_handle);
                    printf("Referenced Offset: 0x%02hhX\n", entry->referenced_offset);
                    if (entry->field_status.string != LAZYBIOS_FIELD_PRESENT) {
                        printf("String: Not Present\n");
                    } else {
                        printf("String: %s\n", entry->string ? entry->string : "Not Specified");
                    }
                    printf("Value:");
                    for (size_t k = 0; k < entry->value_length; k++) { printf(" %02hhX", entry->value[k]); }
                    printf("\n");
                }
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Additional Information\n\n");
    }
}

static void printType41(lazybiosCTX_t *ctx) {
    printf("=== ONBOARD DEVICES EXTENDED INFORMATION ===\n");
    if (!ctx->Type41) ctx->Type41 = lazybiosGetType41(ctx->Type41, &ctx->type41_count, ctx->DMIData);
    if (ctx->Type41 && ctx->type41_count > 0) {
        for (size_t i = 0; i < ctx->type41_count; i++) {
            lazybiosType41_t *type41 = &ctx->Type41[i];
            if (ctx->type41_count > 1) { printf("--- Onboard Device %zu ---\n", i + 1); }
            printf("Reference Designation: %s\n", type41->reference_designation ? type41->reference_designation : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type41, device_type_and_status) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Type: Not Present\n");
                printf("Device Status: Not Present\n");
            } else {
                printf("Device Type: %s\n", lazybiosType41DeviceTypeStr(type41->device_type_and_status));
                printf("Device Status: %s\n", lazybiosType41DeviceStatusStr(type41->device_type_and_status));
            }
            if (LAZYBIOS_FIELD_STATUS(type41, device_type_instance) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device Type Instance: Not Present\n");
            } else {
                printf("Device Type Instance: %hhu\n", type41->device_type_instance);
            }
            if (LAZYBIOS_FIELD_STATUS(type41, segment_group_number) != LAZYBIOS_FIELD_PRESENT) {
                printf("Segment Group Number: Not Present\n");
            } else if (type41->segment_group_number == 0xFFFF) {
                printf("Segment Group Number: Not Applicable\n");
            } else {
                printf("Segment Group Number: %hu\n", type41->segment_group_number);
            }
            if (LAZYBIOS_FIELD_STATUS(type41, bus_number) != LAZYBIOS_FIELD_PRESENT) {
                printf("Bus Number: Not Present\n");
            } else if (type41->bus_number == 0xFF) {
                printf("Bus Number: Not Applicable\n");
            } else {
                printf("Bus Number: %hhu\n", type41->bus_number);
            }
            if (LAZYBIOS_FIELD_STATUS(type41, device_function_number) != LAZYBIOS_FIELD_PRESENT) {
                printf("Device/Function Number: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType41DeviceFunctionStr(type41->device_function_number, buf, sizeof(buf));
                printf("Device/Function Number: %s\n", buf);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Onboard Devices Extended information\n\n");
    }
}

static void printType42(lazybiosCTX_t *ctx) {
    printf("=== MANAGEMENT CONTROLLER HOST INTERFACE ===\n");
    if (!ctx->Type42) ctx->Type42 = lazybiosGetType42(ctx->Type42, &ctx->type42_count, ctx->DMIData);
    if (ctx->Type42 && ctx->type42_count > 0) {
        for (size_t i = 0; i < ctx->type42_count; i++) {
            lazybiosType42_t *type42 = &ctx->Type42[i];
            if (ctx->type42_count > 1) { printf("--- Management Controller Host Interface %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type42, interface_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interface Type: Not Present\n");
            } else {
                printf("Interface Type: %s (0x%02hhX)\n", lazybiosType42InterfaceTypeStr(type42->interface_type), type42->interface_type);
            }
            if (LAZYBIOS_FIELD_STATUS(type42, interface_type_specific_data) != LAZYBIOS_FIELD_PRESENT) {
                printf("Interface Type Specific Data: Not Present\n");
            } else {
                printf("Interface Type Specific Data (%zu bytes):", type42->interface_type_specific_data_size);
                for (size_t j = 0; j < type42->interface_type_specific_data_size; j++) { printf(" %02hhX", type42->interface_type_specific_data[j]); }
                printf("\n");
            }
            if (LAZYBIOS_FIELD_STATUS(type42, number_of_protocol_records) != LAZYBIOS_FIELD_PRESENT) {
                printf("Protocol Record Count: Not Present\n");
            } else {
                printf("Protocol Record Count: %hhu\n", type42->number_of_protocol_records);
            }
            if (LAZYBIOS_FIELD_STATUS(type42, protocol_records) != LAZYBIOS_FIELD_PRESENT) {
                printf("Protocol Records: Not Present\n");
            } else {
                for (size_t j = 0; j < type42->number_of_protocol_records; j++) {
                    lazybiosType42ProtocolRecord_t *protocol = &type42->protocol_records[j];
                    printf("--- Protocol Record %zu ---\n", j + 1);
                    printf("Protocol Type: %s (0x%02hhX)\n", lazybiosType42ProtocolTypeStr(protocol->protocol_type), protocol->protocol_type);
                    printf("Protocol Type Specific Data (%hhu bytes):", protocol->protocol_type_specific_data_length);
                    for (size_t k = 0; k < protocol->protocol_type_specific_data_length; k++) { printf(" %02hhX", protocol->protocol_type_specific_data[k]); }
                    printf("\n");
                }
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Management Controller Host Interface information\n\n");
    }
}

static void printType43(lazybiosCTX_t *ctx) {
    printf("=== TPM DEVICE ===\n");
    if (!ctx->Type43) ctx->Type43 = lazybiosGetType43(ctx->Type43, &ctx->type43_count, ctx->DMIData);
    if (ctx->Type43 && ctx->type43_count > 0) {
        for (size_t i = 0; i < ctx->type43_count; i++) {
            lazybiosType43_t *type43 = &ctx->Type43[i];
            char buf[LAZYBIOS_DECODER_BUF_SIZE];
            if (ctx->type43_count > 1) { printf("--- TPM Device %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type43, vendor_id) != LAZYBIOS_FIELD_PRESENT) {
                printf("Vendor ID: Not Present\n");
            } else {
                printf("Vendor ID: %s\n", type43->vendor_id);
            }
            if (LAZYBIOS_FIELD_STATUS(type43, major_spec_version) != LAZYBIOS_FIELD_PRESENT ||
                LAZYBIOS_FIELD_STATUS(type43, minor_spec_version) != LAZYBIOS_FIELD_PRESENT) {
                printf("TPM Specification Version: Not Present\n");
            } else {
                printf("TPM Specification Version: %hhu.%hhu\n", type43->major_spec_version, type43->minor_spec_version);
            }
            if (LAZYBIOS_FIELD_STATUS(type43, firmware_version_1) != LAZYBIOS_FIELD_PRESENT ||
                LAZYBIOS_FIELD_STATUS(type43, firmware_version_2) != LAZYBIOS_FIELD_PRESENT ||
                LAZYBIOS_FIELD_STATUS(type43, major_spec_version) != LAZYBIOS_FIELD_PRESENT) {
                printf("Firmware Revision: Not Present\n");
            } else {
                lazybiosType43FirmwareVersionStr(type43->major_spec_version, type43->firmware_version_1, type43->firmware_version_2, buf, sizeof(buf));
                printf("Firmware Revision: %s\n", buf);
            }
            printf("Description: %s\n", type43->description ? type43->description : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type43, characteristics) != LAZYBIOS_FIELD_PRESENT) {
                printf("Characteristics: Not Present\n");
            } else {
                lazybiosType43CharacteristicsStr(type43->characteristics, buf, sizeof(buf));
                printf("Characteristics: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type43, oem_defined) != LAZYBIOS_FIELD_PRESENT) {
                printf("OEM-defined: Not Present\n");
            } else {
                printf("OEM-defined: 0x%08X\n", type43->oem_defined);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get TPM Device information\n\n");
    }
}

static void printType44(lazybiosCTX_t *ctx) {
    printf("=== PROCESSOR ADDITIONAL INFORMATION ===\n");
    if (!ctx->Type44) ctx->Type44 = lazybiosGetType44(ctx->Type44, &ctx->type44_count, ctx->DMIData);
    if (ctx->Type44 && ctx->type44_count > 0) {
        for (size_t i = 0; i < ctx->type44_count; i++) {
            lazybiosType44_t *type44 = &ctx->Type44[i];
            if (ctx->type44_count > 1) { printf("--- Processor Additional Information %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type44, referenced_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Referenced Processor Handle: Not Present\n");
            } else {
                printf("Referenced Processor Handle: 0x%04hX\n", type44->referenced_handle);
            }
            if (LAZYBIOS_FIELD_STATUS(type44, block_length) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor-specific Data Length: Not Present\n");
            } else {
                printf("Processor-specific Data Length: %hhu bytes\n", type44->block_length);
            }
            if (LAZYBIOS_FIELD_STATUS(type44, processor_type) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor Type: Not Present\n");
            } else {
                printf("Processor Type: %s\n", lazybiosType44ProcessorTypeStr(type44->processor_type));
            }
            if (LAZYBIOS_FIELD_STATUS(type44, processor_specific_data) != LAZYBIOS_FIELD_PRESENT) {
                printf("Processor-specific Data: Not Present\n");
            } else {
                printf("Processor-specific Data:");
                for (size_t j = 0; j < type44->block_length; j++) { printf(" %02hhX", type44->processor_specific_data[j]); }
                printf("\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Processor Additional Information\n\n");
    }
}

static void printType45(lazybiosCTX_t *ctx) {
    printf("=== FIRMWARE INVENTORY INFORMATION ===\n");
    if (!ctx->Type45) ctx->Type45 = lazybiosGetType45(ctx->Type45, &ctx->type45_count, ctx->DMIData);
    if (ctx->Type45 && ctx->type45_count > 0) {
        for (size_t i = 0; i < ctx->type45_count; i++) {
            lazybiosType45_t *type45 = &ctx->Type45[i];
            if (ctx->type45_count > 1) { printf("--- Firmware Component %zu ---\n", i + 1); }
            printf("Firmware Component Name: %s\n", type45->firmware_component_name ? type45->firmware_component_name : "Not Present");
            printf("Firmware Version: %s\n", type45->firmware_version ? type45->firmware_version : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type45, version_format) != LAZYBIOS_FIELD_PRESENT) {
                printf("Version Format: Not Present\n");
            } else {
                printf("Version Format: %s\n", lazybiosType45VersionFormatStr(type45->version_format));
            }
            printf("Firmware ID: %s\n", type45->firmware_id ? type45->firmware_id : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type45, firmware_id_format) != LAZYBIOS_FIELD_PRESENT) {
                printf("Firmware ID Format: Not Present\n");
            } else {
                printf("Firmware ID Format: %s\n", lazybiosType45FirmwareIDFormatStr(type45->firmware_id_format));
            }
            printf("Release Date: %s\n", type45->release_date ? type45->release_date : "Not Present");
            printf("Manufacturer: %s\n", type45->manufacturer ? type45->manufacturer : "Not Present");
            printf("Lowest Supported Firmware Version: %s\n",
                   type45->lowest_supported_firmware_version ? type45->lowest_supported_firmware_version : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type45, image_size) != LAZYBIOS_FIELD_PRESENT) {
                printf("Image Size: Not Present\n");
            } else if (type45->image_size == UINT64_MAX) {
                printf("Image Size: Unknown\n");
            } else {
                printf("Image Size: %llu bytes\n", (unsigned long long)type45->image_size);
            }
            if (LAZYBIOS_FIELD_STATUS(type45, characteristics) != LAZYBIOS_FIELD_PRESENT) {
                printf("Characteristics: Not Present\n");
            } else {
                char buf[LAZYBIOS_DECODER_BUF_SIZE];
                lazybiosType45CharacteristicsStr(type45->characteristics, buf, sizeof(buf));
                printf("Characteristics: %s\n", buf);
            }
            if (LAZYBIOS_FIELD_STATUS(type45, state) != LAZYBIOS_FIELD_PRESENT) {
                printf("State: Not Present\n");
            } else {
                printf("State: %s\n", lazybiosType45StateStr(type45->state));
            }
            if (LAZYBIOS_FIELD_STATUS(type45, number_of_associated_components) != LAZYBIOS_FIELD_PRESENT) {
                printf("Number of Associated Components: Not Present\n");
            } else {
                printf("Number of Associated Components: %hhu\n", type45->number_of_associated_components);
            }
            if (LAZYBIOS_FIELD_STATUS(type45, associated_component_handles) != LAZYBIOS_FIELD_PRESENT) {
                printf("Associated Component Handles: Not Present\n");
            } else if (type45->number_of_associated_components == 0) {
                printf("Associated Component Handles: None\n");
            } else {
                printf("Associated Component Handles:");
                for (size_t j = 0; j < type45->number_of_associated_components; j++) { printf(" 0x%04hX", type45->associated_component_handles[j]); }
                printf("\n");
            }
            printf("\n");
        }
    } else {
        printf("Failed to get Firmware Inventory information\n\n");
    }
}

static void printType46(lazybiosCTX_t *ctx) {
    printf("=== STRING PROPERTY ===\n");
    if (!ctx->Type46) ctx->Type46 = lazybiosGetType46(ctx->Type46, &ctx->type46_count, ctx->DMIData);
    if (ctx->Type46 && ctx->type46_count > 0) {
        for (size_t i = 0; i < ctx->type46_count; i++) {
            lazybiosType46_t *type46 = &ctx->Type46[i];
            if (ctx->type46_count > 1) { printf("--- String Property %zu ---\n", i + 1); }
            if (LAZYBIOS_FIELD_STATUS(type46, string_property_id) != LAZYBIOS_FIELD_PRESENT) {
                printf("String Property ID: Not Present\n");
            } else {
                printf("String Property ID: %hu (%s)\n", type46->string_property_id, lazybiosType46StringPropertyIDStr(type46->string_property_id));
            }
            printf("String Property Value: %s\n", type46->string_property_value ? type46->string_property_value : "Not Present");
            if (LAZYBIOS_FIELD_STATUS(type46, parent_handle) != LAZYBIOS_FIELD_PRESENT) {
                printf("Parent Handle: Not Present\n");
            } else {
                printf("Parent Handle: 0x%04hX\n", type46->parent_handle);
            }
            printf("\n");
        }
    } else {
        printf("Failed to get String Property information\n\n");
    }
}

int print_smbios_version_info(lazybiosCTX_t *ctx) {
    if (!ctx) return -1;
    printf("=== SMBIOS INFORMATION ===\n");
    lazybiosPrintVer(ctx);
    if (!verbose_output) {
        printf("Table size: %zu bytes\n\n", ctx->DMIData->dmi_len);
        return 0;
    }

    if (ctx->DMIData->entry_tag == SMBIOS_VER_3X) {
        lazybiosSMBIOS3Entry *v3 = ctx->DMIData->entry_union.v3;
        printf("Entry Point Version: 3.x\n");
        printf("Anchor: %c%c%c%c%c\n", v3->anchor[0], v3->anchor[1], v3->anchor[2], v3->anchor[3], v3->anchor[4]);
        printf("Entry Point Length: %u bytes\n", v3->entry_point_length);
        printf("Major Version: %u\n", v3->major_version);
        printf("Minor Version: %u\n", v3->minor_version);
        printf("Docrev: %u\n", v3->docrev);
        printf("Entry Point Revision: %u\n", v3->entry_point_revision);
        printf("Table Max Size: %u bytes\n", v3->structure_table_max_size);
        if (ctx->backend == LAZYBIOS_BACKEND_WINDOWS) {
            printf("Table Address: Not available (Windows API)\n");
        } else {
            printf("Table Address: 0x%lX\n", (unsigned long)v3->structure_table_address);
        }
        printf("Is 64-bit: Yes\n");
    } else if (ctx->DMIData->entry_tag == SMBIOS_VER_2X) {
        lazybiosSMBIOS2Entry *v2 = ctx->DMIData->entry_union.v2;
        printf("Entry Point Version: 2.x\n");
        printf("Anchor: %c%c%c%c\n", v2->anchor[0], v2->anchor[1], v2->anchor[2], v2->anchor[3]);
        printf("Entry Point Length: %u bytes\n", v2->entry_point_length);
        printf("Major Version: %u\n", v2->major_version);
        printf("Minor Version: %u\n", v2->minor_version);
        printf("Maximum Structure Size: %u bytes\n", v2->maximum_structure_size);
        printf("Entry Point Revision: %u\n", v2->entry_point_revision);
        printf("Intermediate Anchor: %c%c%c%c%c\n", v2->intermediate_anchor[0], v2->intermediate_anchor[1], v2->intermediate_anchor[2],
               v2->intermediate_anchor[3], v2->intermediate_anchor[4]);
        printf("Structure Table Length: %u bytes\n", v2->structure_table_length);
        printf("Number of Structures: %u\n", v2->structure_count);
        printf("BCD Revision: %u.%u\n", (v2->bcd_revision >> 4) & 0x0F, v2->bcd_revision & 0x0F);
        if (ctx->backend == LAZYBIOS_BACKEND_WINDOWS) {
            printf("Table Address: Not available (Windows API)\n");
        } else {
            printf("Table Address: 0x%lX\n", (unsigned long)v2->structure_table_address);
        }
        printf("Is 64-bit: No\n");
    } else {
        printf("Entry Point Version: Unknown\n");
        printf("Table Length: Not Present\n");
        printf("Table Address: Not Present\n");
        printf("Is 64-bit: Not Present\n");
    }
    printf("\n");
    return 0;
}

static void print_tool_versions(void) { printf("Using:\nlazybios: %s\nlazydmi: %s\n", LAZYBIOS_VER, LAZYDMI_VER); }

static int parse_type_number(const char *arg, int *out) {
    char *endptr;
    long num = strtol(arg, &endptr, 10);
    if (*endptr == '\0' && num >= 0 && num <= 46) {
        *out = (int)num;
        return 0;
    }

    // Searching in the list if it's not a number
    for (int i = 0; type_aliases[i].name != NULL; i++) {
        if (strcmp(arg, type_aliases[i].name) == 0) {
            *out = type_aliases[i].number;
            return 0;
        }
    }

    return -1;
}

static void print_usage(FILE *out, const char *progname) {
    fprintf(out, "Usage: %s [options]\n\n", progname);
    fprintf(out, "Inspect the host SMBIOS table, or a table captured in files.\n");
    fprintf(out, "By default, only present types and a concise entry-point summary are shown.\n\n");
    fprintf(out, "Output:\n");
    fprintf(out, "  -t, --type NUMBER          Show one SMBIOS type (0-46)\n");
    fprintf(out, "  -v, --verbose              Show full entry-point and compatibility details\n");
    fprintf(out, "  -c, --compact              Use concise output (the default)\n\n");
    fprintf(out, "Input:\n");
    fprintf(out, "  -s, --sources ENTRY DMI    Read separate entry-point and DMI files\n");
    fprintf(out, "  -f, --single-source FILE   Read one merged SMBIOS file\n");
    fprintf(out, "  -d, --dump [DIRECTORY]     Dump the host data (default directory: .)\n\n");
    fprintf(out, "General:\n");
    fprintf(out, "  -h, --help                 Show this help\n");
    fprintf(out, "  -h, --help types           Shows what each type means\n");
    fprintf(out, "  -V, --version              Show lazybios and lazydmi versions\n\n");
    fprintf(out, "Examples:\n");
    fprintf(out, "  %s -t 0\n", progname);
    fprintf(out, "  %s -v -t 17\n", progname);
    fprintf(out, "  %s -s smbios_entry_point DMI\n", progname);
}

static void print_type_help(FILE *out) {
    fprintf(out, "Each Type and it's meaning:\n");
    fprintf(out, "  Type 0: BIOS Information\n");
    fprintf(out, "  Type 1: System Information\n");
    fprintf(out, "  Type 2: Baseboard Information\n");
    fprintf(out, "  Type 3: System Enclosure\n");
    fprintf(out, "  Type 4: Processor Information\n");
    fprintf(out, "  Type 5: Memory Controller Information (obsolete)\n");
    fprintf(out, "  Type 6: Memory Module Information (obsolete)\n");
    fprintf(out, "  Type 7: Cache Information\n");
    fprintf(out, "  Type 8: Port Connector Information\n");
    fprintf(out, "  Type 9: System Slots\n");
    fprintf(out, "  Type 10: Onboard Devices Information\n");
    fprintf(out, "  Type 11: OEM Strings\n");
    fprintf(out, "  Type 12: System Configuration Options\n");
    fprintf(out, "  Type 13: BIOS Language Information\n");
    fprintf(out, "  Type 14: Group Associations\n");
    fprintf(out, "  Type 15: System Event Log\n");
    fprintf(out, "  Type 16: Physical Memory Array\n");
    fprintf(out, "  Type 17: Memory Device\n");
    fprintf(out, "  Type 18: 32-bit Memory Error Information\n");
    fprintf(out, "  Type 19: Memory Array Mapped Address\n");
    fprintf(out, "  Type 20: Memory Device Mapped Address\n");
    fprintf(out, "  Type 21: Built-in Pointing Device\n");
    fprintf(out, "  Type 22: Portable Battery\n");
    fprintf(out, "  Type 23: System Reset\n");
    fprintf(out, "  Type 24: Hardware Security\n");
    fprintf(out, "  Type 25: System Power Controls\n");
    fprintf(out, "  Type 26: Voltage Probe\n");
    fprintf(out, "  Type 27: Cooling Device\n");
    fprintf(out, "  Type 28: Temperature Probe\n");
    fprintf(out, "  Type 29: Electrical Current Probe\n");
    fprintf(out, "  Type 30: Out-of-Band Remote Access\n");
    fprintf(out, "  Type 31: Boot Integrity Services Entry Point\n");
    fprintf(out, "  Type 32: System Boot Information\n");
    fprintf(out, "  Type 33: 64-bit Memory Error Information\n");
    fprintf(out, "  Type 34: Management Device\n");
    fprintf(out, "  Type 35: Management Device Component\n");
    fprintf(out, "  Type 36: Management Device Threshold Data\n");
    fprintf(out, "  Type 37: Memory Channel\n");
    fprintf(out, "  Type 38: IPMI Device Information\n");
    fprintf(out, "  Type 39: System Power Supply\n");
    fprintf(out, "  Type 40: Additional Information\n");
    fprintf(out, "  Type 41: Onboard Devices Extended Information\n");
    fprintf(out, "  Type 42: Management Controller Host Interface\n");
    fprintf(out, "  Type 43: TPM Device\n");
    fprintf(out, "  Type 44: Processor Additional Information\n");
    fprintf(out, "  Type 45: Firmware Inventory Information\n");
    fprintf(out, "  Type 46: Inactive structure (not used)\n");
}

int main(int argc, const char *argv[]) {
    int print_all = 1;
    int type_to_print = -1;
    const char *dump_dir = NULL;
    const char *entry_file = NULL;
    const char *dmi_file = NULL;
    const char *single_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                if (strcmp(argv[i + 1], "types") == 0) {
                    print_type_help(stdout);
                } else {
                    printf("Did you mean:\n %s types\n", argv[i]);
                }
            } else print_usage(stdout, argv[0]);
            return 0;
        } else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-V") == 0) {
            print_tool_versions();
            return 0;
        } else if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
            verbose_output = 1;
            compact_output = 0;
        } else if (strcmp(argv[i], "--compact") == 0 || strcmp(argv[i], "-c") == 0) {
            verbose_output = 0;
            compact_output = 1;
        } else if (strcmp(argv[i], "--type") == 0 || strcmp(argv[i], "-t") == 0) {
            if (i + 1 >= argc || parse_type_number(argv[i + 1], &type_to_print) != 0) {
                fprintf(stderr, "Error: %s requires a type number from 0 to 46\n\n", argv[i]);
                print_usage(stderr, argv[0]);
                return 2;
            }
            print_all = 0;
            i++;
        } else if (strcmp(argv[i], "--dump") == 0 || strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                dump_dir = argv[i + 1];
                i++;
            } else {
                dump_dir = ".";
            }
        } else if (strcmp(argv[i], "--sources") == 0 || strcmp(argv[i], "-s") == 0) {
            if (i + 2 < argc) {
                entry_file = argv[i + 1];
                dmi_file = argv[i + 2];
                i += 2;
            } else {
                fprintf(stderr, "Error: %s requires ENTRY and DMI files\n\n", argv[i]);
                print_usage(stderr, argv[0]);
                return 2;
            }
        } else if (strcmp(argv[i], "--single-source") == 0 || strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                single_file = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: %s requires a file\n\n", argv[i]);
                print_usage(stderr, argv[0]);
                return 2;
            }
        } else {
            fprintf(stderr, "Error: unknown option '%s'\n\n", argv[i]);
            print_usage(stderr, argv[0]);
            return 2;
        }
    }

    int input_modes = (dump_dir != NULL) + (entry_file != NULL) + (single_file != NULL);
    if (input_modes > 1) {
        fprintf(stderr, "Error: --dump, --sources, and --single-source cannot be combined\n");
        return 2;
    }

    print_tool_versions();
    if (verbose_output) printf("=============================================\n");
    printf("\n");

    lazybiosCTX_t *ctx = lazybiosCTXNew();
    if (!ctx) {
        fprintf(stderr, "Failed to allocate lazybios context\n");
        return 1;
    }

    if (dump_dir) {
        if (lazybiosInit(ctx) != 0) {
            fprintf(stderr, "Failed to read SMBIOS data from the host\n");
            lazybiosCleanup(ctx);
            return 1;
        }
        char path_entry[1024];
        char path_dmi[1024];
#if defined(_WIN32) || defined(_WIN64)
        snprintf(path_dmi, sizeof(path_dmi), "%s\\DMI.bin", dump_dir);
        snprintf(path_entry, sizeof(path_entry), "%s\\generated_smbios_entry_point.bin", dump_dir);
#else
        snprintf(path_dmi, sizeof(path_dmi), "%s/DMI", dump_dir);
        snprintf(path_entry, sizeof(path_entry), "%s/smbios_entry_point", dump_dir);
#endif
        FILE *entry = NULL;
        FILE *dmi = NULL;
        if (ctx->backend != LAZYBIOS_BACKEND_UNKNOWN) {
            entry = fopen(path_entry, "wb");
            if (!entry) {
                fprintf(stderr, "Failed to open '%s': %s\n", path_entry, strerror(errno));
                lazybiosCleanup(ctx);
                return 1;
            }
            dmi = fopen(path_dmi, "wb");
            if (!dmi) {
                fprintf(stderr, "Failed to open '%s': %s\n", path_dmi, strerror(errno));
                fclose(entry);
                lazybiosCleanup(ctx);
                return 1;
            }
            fwrite(ctx->DMIData->dmi_data, 1, ctx->DMIData->dmi_len, dmi);
            fwrite(ctx->DMIData->entry_data, 1, ctx->DMIData->entry_len, entry);
            fclose(entry);
            fclose(dmi);
            printf("%s and %s dumped successfully\n", path_entry, path_dmi);
        } else {
            fprintf(stderr, "No host backend is available; unable to dump SMBIOS data\n");
            lazybiosCleanup(ctx);
            return 1;
        }
        lazybiosCleanup(ctx);
        return 0;
    }
    if (entry_file && dmi_file) {
        if (lazybiosFile(ctx, entry_file, dmi_file) != 0) {
            fprintf(stderr, "Failed to initialize lazybios from files\n");
            lazybiosCleanup(ctx);
            return 1;
        }
    } else if (single_file) {
        if (lazybiosSingleFile(ctx, single_file) != 0) {
            fprintf(stderr, "Failed to initialize lazybios from single file\n");
            lazybiosCleanup(ctx);
            return 1;
        }
    } else {
        if (lazybiosInit(ctx) != 0) {
            fprintf(stderr, "Failed to initialize lazybios library\n");
            lazybiosCleanup(ctx);
            return 1;
        }
    }
    if (verbose_output) printf("Library initialized successfully!\n\n");
    print_smbios_version_info(ctx);
    if (print_all) {
        if (!ctx->Type0) ctx->Type0 = lazybiosGetType0(ctx->Type0, ctx->DMIData);
        if (ctx->Type0 || verbose_output) printType0(ctx);
        if (!ctx->Type1) ctx->Type1 = lazybiosGetType1(ctx->Type1, ctx->DMIData);
        if (ctx->Type1 || verbose_output) printType1(ctx);
        if (!ctx->Type2) ctx->Type2 = lazybiosGetType2(ctx->Type2, &ctx->type2_count, ctx->DMIData);
        if (ctx->type2_count > 0 || verbose_output) printType2(ctx);
        if (!ctx->Type3) ctx->Type3 = lazybiosGetType3(ctx->Type3, &ctx->type3_count, ctx->DMIData);
        if (ctx->type3_count > 0 || verbose_output) printType3(ctx);
        if (!ctx->Type4) ctx->Type4 = lazybiosGetType4(ctx->Type4, &ctx->type4_count, ctx->DMIData);
        if (ctx->type4_count > 0 || verbose_output) printType4(ctx);
        if (!ctx->Type5) ctx->Type5 = lazybiosGetType5(ctx->Type5, &ctx->type5_count, ctx->DMIData);
        if (ctx->type5_count > 0 || verbose_output) printType5(ctx);
        if (!ctx->Type6) ctx->Type6 = lazybiosGetType6(ctx->Type6, &ctx->type6_count, ctx->DMIData);
        if (ctx->type6_count > 0 || verbose_output) printType6(ctx);
        if (!ctx->Type7) ctx->Type7 = lazybiosGetType7(ctx->Type7, &ctx->type7_count, ctx->DMIData);
        if (ctx->type7_count > 0 || verbose_output) printType7(ctx);
        if (!ctx->Type8) ctx->Type8 = lazybiosGetType8(ctx->Type8, &ctx->type8_count, ctx->DMIData);
        if (ctx->type8_count > 0 || verbose_output) printType8(ctx);
        if (!ctx->Type9) ctx->Type9 = lazybiosGetType9(ctx->Type9, &ctx->type9_count, ctx->DMIData);
        if (ctx->type9_count > 0 || verbose_output) printType9(ctx);
        if (!ctx->Type10) ctx->Type10 = lazybiosGetType10(ctx->Type10, &ctx->type10_count, ctx->DMIData);
        if (ctx->type10_count > 0 || verbose_output) printType10(ctx);
        if (!ctx->Type11) ctx->Type11 = lazybiosGetType11(ctx->Type11, &ctx->type11_count, ctx->DMIData);
        if (ctx->type11_count > 0 || verbose_output) printType11(ctx);
        if (!ctx->Type12) ctx->Type12 = lazybiosGetType12(ctx->Type12, &ctx->type12_count, ctx->DMIData);
        if (ctx->type12_count > 0 || verbose_output) printType12(ctx);
        if (!ctx->Type13) ctx->Type13 = lazybiosGetType13(ctx->Type13, &ctx->type13_count, ctx->DMIData);
        if (ctx->type13_count > 0 || verbose_output) printType13(ctx);
        if (!ctx->Type14) ctx->Type14 = lazybiosGetType14(ctx->Type14, &ctx->type14_count, ctx->DMIData);
        if (ctx->type14_count > 0 || verbose_output) printType14(ctx);
        if (!ctx->Type15) ctx->Type15 = lazybiosGetType15(ctx->Type15, &ctx->type15_count, ctx->DMIData);
        if (ctx->type15_count > 0 || verbose_output) printType15(ctx);
        if (!ctx->Type16) ctx->Type16 = lazybiosGetType16(ctx->Type16, &ctx->type16_count, ctx->DMIData);
        if (ctx->type16_count > 0 || verbose_output) printType16(ctx);
        if (!ctx->Type17) ctx->Type17 = lazybiosGetType17(ctx->Type17, &ctx->type17_count, ctx->DMIData);
        if (ctx->type17_count > 0 || verbose_output) printType17(ctx);
        if (!ctx->Type18) ctx->Type18 = lazybiosGetType18(ctx->Type18, &ctx->type18_count, ctx->DMIData);
        if (ctx->type18_count > 0 || verbose_output) printType18(ctx);
        if (!ctx->Type19) ctx->Type19 = lazybiosGetType19(ctx->Type19, &ctx->type19_count, ctx->DMIData);
        if (ctx->type19_count > 0 || verbose_output) printType19(ctx);
        if (!ctx->Type20) ctx->Type20 = lazybiosGetType20(ctx->Type20, &ctx->type20_count, ctx->DMIData);
        if (ctx->type20_count > 0 || verbose_output) printType20(ctx);
        if (!ctx->Type21) ctx->Type21 = lazybiosGetType21(ctx->Type21, &ctx->type21_count, ctx->DMIData);
        if (ctx->type21_count > 0 || verbose_output) printType21(ctx);
        if (!ctx->Type22) ctx->Type22 = lazybiosGetType22(ctx->Type22, &ctx->type22_count, ctx->DMIData);
        if (ctx->type22_count > 0 || verbose_output) printType22(ctx);
        if (!ctx->Type23) ctx->Type23 = lazybiosGetType23(ctx->Type23, &ctx->type23_count, ctx->DMIData);
        if (ctx->type23_count > 0 || verbose_output) printType23(ctx);
        if (!ctx->Type24) ctx->Type24 = lazybiosGetType24(ctx->Type24, &ctx->type24_count, ctx->DMIData);
        if (ctx->type24_count > 0 || verbose_output) printType24(ctx);
        if (!ctx->Type25) ctx->Type25 = lazybiosGetType25(ctx->Type25, &ctx->type25_count, ctx->DMIData);
        if (ctx->type25_count > 0 || verbose_output) printType25(ctx);
        if (!ctx->Type26) ctx->Type26 = lazybiosGetType26(ctx->Type26, &ctx->type26_count, ctx->DMIData);
        if (ctx->type26_count > 0 || verbose_output) printType26(ctx);
        if (!ctx->Type27) ctx->Type27 = lazybiosGetType27(ctx->Type27, &ctx->type27_count, ctx->DMIData);
        if (ctx->type27_count > 0 || verbose_output) printType27(ctx);
        if (!ctx->Type28) ctx->Type28 = lazybiosGetType28(ctx->Type28, &ctx->type28_count, ctx->DMIData);
        if (ctx->type28_count > 0 || verbose_output) printType28(ctx);
        if (!ctx->Type29) ctx->Type29 = lazybiosGetType29(ctx->Type29, &ctx->type29_count, ctx->DMIData);
        if (ctx->type29_count > 0 || verbose_output) printType29(ctx);
        if (!ctx->Type30) ctx->Type30 = lazybiosGetType30(ctx->Type30, &ctx->type30_count, ctx->DMIData);
        if (ctx->type30_count > 0 || verbose_output) printType30(ctx);
        if (!ctx->Type31) ctx->Type31 = lazybiosGetType31(ctx->Type31, &ctx->type31_count, ctx->DMIData);
        if (ctx->type31_count > 0 || verbose_output) printType31(ctx);
        if (!ctx->Type32) ctx->Type32 = lazybiosGetType32(ctx->Type32, &ctx->type32_count, ctx->DMIData);
        if (ctx->type32_count > 0 || verbose_output) printType32(ctx);
        if (!ctx->Type33) ctx->Type33 = lazybiosGetType33(ctx->Type33, &ctx->type33_count, ctx->DMIData);
        if (ctx->type33_count > 0 || verbose_output) printType33(ctx);
        if (!ctx->Type34) ctx->Type34 = lazybiosGetType34(ctx->Type34, &ctx->type34_count, ctx->DMIData);
        if (ctx->type34_count > 0 || verbose_output) printType34(ctx);
        if (!ctx->Type35) ctx->Type35 = lazybiosGetType35(ctx->Type35, &ctx->type35_count, ctx->DMIData);
        if (ctx->type35_count > 0 || verbose_output) printType35(ctx);
        if (!ctx->Type36) ctx->Type36 = lazybiosGetType36(ctx->Type36, &ctx->type36_count, ctx->DMIData);
        if (ctx->type36_count > 0 || verbose_output) printType36(ctx);
        if (!ctx->Type37) ctx->Type37 = lazybiosGetType37(ctx->Type37, &ctx->type37_count, ctx->DMIData);
        if (ctx->type37_count > 0 || verbose_output) printType37(ctx);
        if (!ctx->Type38) ctx->Type38 = lazybiosGetType38(ctx->Type38, &ctx->type38_count, ctx->DMIData);
        if (ctx->type38_count > 0 || verbose_output) printType38(ctx);
        if (!ctx->Type39) ctx->Type39 = lazybiosGetType39(ctx->Type39, &ctx->type39_count, ctx->DMIData);
        if (ctx->type39_count > 0 || verbose_output) printType39(ctx);
        if (!ctx->Type40) ctx->Type40 = lazybiosGetType40(ctx->Type40, &ctx->type40_count, ctx->DMIData);
        if (ctx->type40_count > 0 || verbose_output) printType40(ctx);
        if (!ctx->Type41) ctx->Type41 = lazybiosGetType41(ctx->Type41, &ctx->type41_count, ctx->DMIData);
        if (ctx->type41_count > 0 || verbose_output) printType41(ctx);
        if (!ctx->Type42) ctx->Type42 = lazybiosGetType42(ctx->Type42, &ctx->type42_count, ctx->DMIData);
        if (ctx->type42_count > 0 || verbose_output) printType42(ctx);
        if (!ctx->Type43) ctx->Type43 = lazybiosGetType43(ctx->Type43, &ctx->type43_count, ctx->DMIData);
        if (ctx->type43_count > 0 || verbose_output) printType43(ctx);
        if (!ctx->Type44) ctx->Type44 = lazybiosGetType44(ctx->Type44, &ctx->type44_count, ctx->DMIData);
        if (ctx->type44_count > 0 || verbose_output) printType44(ctx);
        if (!ctx->Type45) ctx->Type45 = lazybiosGetType45(ctx->Type45, &ctx->type45_count, ctx->DMIData);
        if (ctx->type45_count > 0 || verbose_output) printType45(ctx);
        if (!ctx->Type46) ctx->Type46 = lazybiosGetType46(ctx->Type46, &ctx->type46_count, ctx->DMIData);
        if (ctx->type46_count > 0 || verbose_output) printType46(ctx);
    } else {

        switch (type_to_print) {
            case 0:
                if (!ctx->Type0) ctx->Type0 = lazybiosGetType0(ctx->Type0, ctx->DMIData);
                printType0(ctx);
                break;
            case 1:
                if (!ctx->Type1) ctx->Type1 = lazybiosGetType1(ctx->Type1, ctx->DMIData);
                printType1(ctx);
                break;
            case 2:
                if (!ctx->Type2) ctx->Type2 = lazybiosGetType2(ctx->Type2, &ctx->type2_count, ctx->DMIData);
                printType2(ctx);
                break;
            case 3:
                if (!ctx->Type3) ctx->Type3 = lazybiosGetType3(ctx->Type3, &ctx->type3_count, ctx->DMIData);
                printType3(ctx);
                break;
            case 4:
                if (!ctx->Type4) ctx->Type4 = lazybiosGetType4(ctx->Type4, &ctx->type4_count, ctx->DMIData);
                printType4(ctx);
                break;
            case 5:
                if (!ctx->Type5) ctx->Type5 = lazybiosGetType5(ctx->Type5, &ctx->type5_count, ctx->DMIData);
                printType5(ctx);
                break;
            case 6:
                if (!ctx->Type6) ctx->Type6 = lazybiosGetType6(ctx->Type6, &ctx->type6_count, ctx->DMIData);
                printType6(ctx);
                break;
            case 7:
                if (!ctx->Type7) ctx->Type7 = lazybiosGetType7(ctx->Type7, &ctx->type7_count, ctx->DMIData);
                printType7(ctx);
                break;
            case 8:
                if (!ctx->Type8) ctx->Type8 = lazybiosGetType8(ctx->Type8, &ctx->type8_count, ctx->DMIData);
                printType8(ctx);
                break;
            case 9:
                if (!ctx->Type9) ctx->Type9 = lazybiosGetType9(ctx->Type9, &ctx->type9_count, ctx->DMIData);
                printType9(ctx);
                break;
            case 10:
                if (!ctx->Type10) ctx->Type10 = lazybiosGetType10(ctx->Type10, &ctx->type10_count, ctx->DMIData);
                printType10(ctx);
                break;
            case 11:
                if (!ctx->Type11) ctx->Type11 = lazybiosGetType11(ctx->Type11, &ctx->type11_count, ctx->DMIData);
                printType11(ctx);
                break;
            case 12:
                if (!ctx->Type12) ctx->Type12 = lazybiosGetType12(ctx->Type12, &ctx->type12_count, ctx->DMIData);
                printType12(ctx);
                break;
            case 13:
                if (!ctx->Type13) ctx->Type13 = lazybiosGetType13(ctx->Type13, &ctx->type13_count, ctx->DMIData);
                printType13(ctx);
                break;
            case 14:
                if (!ctx->Type14) ctx->Type14 = lazybiosGetType14(ctx->Type14, &ctx->type14_count, ctx->DMIData);
                printType14(ctx);
                break;
            case 15:
                if (!ctx->Type15) ctx->Type15 = lazybiosGetType15(ctx->Type15, &ctx->type15_count, ctx->DMIData);
                printType15(ctx);
                break;
            case 16:
                if (!ctx->Type16) ctx->Type16 = lazybiosGetType16(ctx->Type16, &ctx->type16_count, ctx->DMIData);
                printType16(ctx);
                break;
            case 17:
                if (!ctx->Type17) ctx->Type17 = lazybiosGetType17(ctx->Type17, &ctx->type17_count, ctx->DMIData);
                printType17(ctx);
                break;
            case 18:
                if (!ctx->Type18) ctx->Type18 = lazybiosGetType18(ctx->Type18, &ctx->type18_count, ctx->DMIData);
                printType18(ctx);
                break;
            case 19:
                if (!ctx->Type19) ctx->Type19 = lazybiosGetType19(ctx->Type19, &ctx->type19_count, ctx->DMIData);
                printType19(ctx);
                break;
            case 20:
                if (!ctx->Type20) ctx->Type20 = lazybiosGetType20(ctx->Type20, &ctx->type20_count, ctx->DMIData);
                printType20(ctx);
                break;
            case 21:
                if (!ctx->Type21) ctx->Type21 = lazybiosGetType21(ctx->Type21, &ctx->type21_count, ctx->DMIData);
                printType21(ctx);
                break;
            case 22:
                if (!ctx->Type22) ctx->Type22 = lazybiosGetType22(ctx->Type22, &ctx->type22_count, ctx->DMIData);
                printType22(ctx);
                break;
            case 23:
                if (!ctx->Type23) ctx->Type23 = lazybiosGetType23(ctx->Type23, &ctx->type23_count, ctx->DMIData);
                printType23(ctx);
                break;
            case 24:
                if (!ctx->Type24) ctx->Type24 = lazybiosGetType24(ctx->Type24, &ctx->type24_count, ctx->DMIData);
                printType24(ctx);
                break;
            case 25:
                if (!ctx->Type25) ctx->Type25 = lazybiosGetType25(ctx->Type25, &ctx->type25_count, ctx->DMIData);
                printType25(ctx);
                break;
            case 26:
                if (!ctx->Type26) ctx->Type26 = lazybiosGetType26(ctx->Type26, &ctx->type26_count, ctx->DMIData);
                printType26(ctx);
                break;
            case 27:
                if (!ctx->Type27) ctx->Type27 = lazybiosGetType27(ctx->Type27, &ctx->type27_count, ctx->DMIData);
                printType27(ctx);
                break;
            case 28:
                if (!ctx->Type28) ctx->Type28 = lazybiosGetType28(ctx->Type28, &ctx->type28_count, ctx->DMIData);
                printType28(ctx);
                break;
            case 29:
                if (!ctx->Type29) ctx->Type29 = lazybiosGetType29(ctx->Type29, &ctx->type29_count, ctx->DMIData);
                printType29(ctx);
                break;
            case 30:
                if (!ctx->Type30) ctx->Type30 = lazybiosGetType30(ctx->Type30, &ctx->type30_count, ctx->DMIData);
                printType30(ctx);
                break;
            case 31:
                if (!ctx->Type31) ctx->Type31 = lazybiosGetType31(ctx->Type31, &ctx->type31_count, ctx->DMIData);
                printType31(ctx);
                break;
            case 32:
                if (!ctx->Type32) ctx->Type32 = lazybiosGetType32(ctx->Type32, &ctx->type32_count, ctx->DMIData);
                printType32(ctx);
                break;
            case 33:
                if (!ctx->Type33) ctx->Type33 = lazybiosGetType33(ctx->Type33, &ctx->type33_count, ctx->DMIData);
                printType33(ctx);
                break;
            case 34:
                if (!ctx->Type34) ctx->Type34 = lazybiosGetType34(ctx->Type34, &ctx->type34_count, ctx->DMIData);
                printType34(ctx);
                break;
            case 35:
                if (!ctx->Type35) ctx->Type35 = lazybiosGetType35(ctx->Type35, &ctx->type35_count, ctx->DMIData);
                printType35(ctx);
                break;
            case 36:
                if (!ctx->Type36) ctx->Type36 = lazybiosGetType36(ctx->Type36, &ctx->type36_count, ctx->DMIData);
                printType36(ctx);
                break;
            case 37:
                if (!ctx->Type37) ctx->Type37 = lazybiosGetType37(ctx->Type37, &ctx->type37_count, ctx->DMIData);
                printType37(ctx);
                break;
            case 38:
                if (!ctx->Type38) ctx->Type38 = lazybiosGetType38(ctx->Type38, &ctx->type38_count, ctx->DMIData);
                printType38(ctx);
                break;
            case 39:
                if (!ctx->Type39) ctx->Type39 = lazybiosGetType39(ctx->Type39, &ctx->type39_count, ctx->DMIData);
                printType39(ctx);
                break;
            case 40:
                if (!ctx->Type40) ctx->Type40 = lazybiosGetType40(ctx->Type40, &ctx->type40_count, ctx->DMIData);
                printType40(ctx);
                break;
            case 41:
                if (!ctx->Type41) ctx->Type41 = lazybiosGetType41(ctx->Type41, &ctx->type41_count, ctx->DMIData);
                printType41(ctx);
                break;
            case 42:
                if (!ctx->Type42) ctx->Type42 = lazybiosGetType42(ctx->Type42, &ctx->type42_count, ctx->DMIData);
                printType42(ctx);
                break;
            case 43:
                if (!ctx->Type43) ctx->Type43 = lazybiosGetType43(ctx->Type43, &ctx->type43_count, ctx->DMIData);
                printType43(ctx);
                break;
            case 44:
                if (!ctx->Type44) ctx->Type44 = lazybiosGetType44(ctx->Type44, &ctx->type44_count, ctx->DMIData);
                printType44(ctx);
                break;
            case 45:
                if (!ctx->Type45) ctx->Type45 = lazybiosGetType45(ctx->Type45, &ctx->type45_count, ctx->DMIData);
                printType45(ctx);
                break;
            case 46:
                if (!ctx->Type46) ctx->Type46 = lazybiosGetType46(ctx->Type46, &ctx->type46_count, ctx->DMIData);
                printType46(ctx);
                break;
            default:
                fprintf(stderr, "Error: Type %d is not implemented or invalid\n", type_to_print);
                lazybiosCleanup(ctx);
                return 2;
        }
    }
    if (lazybiosCleanup(ctx) == 0) {
        if (verbose_output) printf("Library cleanup completed!\n");
    } else {
        fprintf(stderr, "Could not complete library cleanup\n");
        return 1;
    }
    if (verbose_output) printf("Operation completed successfully!\n");
    return 0;
}
