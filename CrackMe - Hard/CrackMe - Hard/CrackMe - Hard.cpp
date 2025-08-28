#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <vector>
#include <windows.h>
#include <thread>
#include <ctime>
#include <winternl.h>
#include <chrono>
#include <curl/curl.h>

using namespace std;

map<string, string> parameters;
map<string, string> rebuild
{
    {"f3!K9m@Z2xP&dQ7vR$1", "A"},
    {"L8#jN2%hV1p*Rz9wQ6@", "B"},
    {"xD3^qT5&lM7!sF2kH0#", "C"},
    {"aP1$wE4@cZ8^vR7tL9&", "D"},
    {"J6*oK3!bQ2^fY9#uH1$", "E"},
    {"nM0&dR5@xL8!pV3^sQ7", "F"},
    {"T2#vF8!kB6^hZ1&yN4", "G"},
    {"eC7@qP3$wL9&jR2^mX6", "H"},
    {"U5!gH2^sD8#oF1&zQ4", "I"},
    {"yN1$kV9!tM3^bL6&xR7", "J"},
    {"O4&hJ2^cP8!eQ5#vW0", "K"},
    {"fX3!rS6@dL9^mT2&yK1", "L"},
    {"Q7$wB1!vN5^pH2&jZ8", "M"},
    {"kL0@tR4#yF9!sD3^hV6", "N"},
    {"nP2^mC7&xJ1!vK5$wH9", "O"},
    {"zT6!dL3@qR8^hN0&fV2", "P"},
    {"bG1#oH9^kJ5!sP3&xM7", "Q"},
    {"U4$wF2!mL7^cT1&nQ8", "R"},
    {"pD9^kB3!vR6&yJ2#fX5", "S"},
    {"sH0&jN5^tL8!xC2@qV7", "T"},
    {"mK3!fP7@rD1^vZ9&yB4", "U"},
    {"eQ8^hG2!cM5&nT0#kJ6", "V"},
    {"wR1!sL9@bV4^tP3&xH7", "W"},
    {"yF2^dK6!mN8&zC1#qJ5", "X"},
    {"tP0&vR7^kH3!sL5$wD2", "Y"},
    {"nM4!cQ1@xJ9^bF2&yV8", "Z"},
    {"rL2^pH8!dS5&kN1#fT6", "a"},
    {"vC3!mK7@qJ4^wB0&xR9", "b"},
    {"tF5^hD1!nP6&yL2#sG8", "c"},
    {"kQ0&fV4^rH7!cN3@wM9", "d"},
    {"xJ2!bL8^pD1&yF5#vR6", "e"},
    {"mH3@qT9!kS2^dP4&zN7", "f"},
    {"wB6!cR1^vK5&jL3#tF8", "g"},
    {"nD0&fG4^sH7!pM2@xQ9", "h"},
    {"yL2!mC8^rJ1&vK5#bT6", "i"},
    {"pF3^kN7!dS4&hL0#tR9", "j"},
    {"qH1&vM5^xP2!cB7@jL6", "k"},
    {"rK8!tD3^nF1&yQ5#sH2", "l"},
    {"bN4^mJ0!vL6&kT3#wP7", "m"},
    {"dQ2&fR7^sH1!pL5@xK8", "n"},
    {"zC5!rV3^kN2&jM7#tF1", "o"},
    {"hL9^qB4!nP1&yD6#sR3", "p"},
    {"xJ0&vF7^mK2!cT5@bH9", "q"},
    {"tP3!dL8^rN1&yF6#kV4", "r"},
    {"mH2^kS9!qD0&nL5#zJ7", "s"},
    {"wB1&cR5^vK3!jL8@tF2", "t"},
    {"nD7!fG0^sH4&yM2#pQ6", "u"},
    {"yL6^mC1!rJ5&vK9#bT3", "v"},
    {"pF0&kN4^dS7!hL1@tR5", "w"},
    {"qH3!vM6^xP1&cB9#jL2", "x"},
    {"rK5^tD0!nF8&yQ3#sH7", "y"},
    {"bN2&jM4^vL9!kT0#wP5", "z"},
    {"dQ6!fR1^sH3&yL5#pK7", "0"},
    {"zC0&nV8^kP2!jM5@tF4", "1"},
    {"hL3!qB7^nP0&yD2#sR9", "2"},
    {"xJ5^vF1!mK3&cT8#bH2", "3"},
    {"tP9&dL2^rN5!yF1@kV6", "4"},
    {"mH8!kS0^qD4&nL2#zJ5", "5"},
    {"wB2^cR7!vK1&jL4#tF9", "6"},
    {"nD3&fG5^sH8!pM0@xQ1", "7"},
    {"yL9!mC4^rJ0&vK3#bT7", "8"},
    {"pF1^kN6!dS3&hL7#tR0", "9"},
    {"qH7&vM2^xP5!cB0#jL3", "!"},
    {"rK0^tD5!nF3&yQ1#sH6", "@"},
    {"bN1&jM9^vL2!kT8#wP4", "#"},
    {"dQ3!fR8^sH0&yL7#pK2", "$"},
    {"zC6^nV1!kP4&jM8#tF0", "%"},
    {"hL5&qB2^nP7!yD3#sR1", "^"},
    {"xJ8!vF0^mK5&cT2#bH6", "&"},
    {"tP1^dL6!rN3&yF8#kV0", "*"},
    {"mH0&kS5^qD2!nL7#zJ3", "("},
    {"wB3!cR1^vK6&jL0#tF5", ")"},
    {"nD9^fG2!sH4&yM1#pQ8", "-"},
    {"yL0&nC5^rJ2!vK7#bT1", "_"},
    {"pF6!kN3^dS9&hL2#tR4", "="},
    {"qH2^vM0!xP7&cB5#jL8", "+"},
    {"rK4&bD1^nF5!yQ0#sH7", "["},
    {"bN5^jM2!vL8&kT1#wP3", "]"},
    {"dQ7&fR0^sH4!yL2#pK6", "{"},
    {"zC2!nV5^kP1&jM3#tF8", "}"},
    {"hL9^qB3!nP6&yD0#sR4", ";"},
    {"xJ1&vF8^mK2!cT5#bH0", ":"},
    {"tP4!dL0^rN7&yF3#kV1", "'"},
    {"mH2^kS6!qD0&nL5#zJ8", ","},
{"wB0&cR4^vK7!jL2#tF9", "."},
{"nD5!fG1^sH6&yM3#pQ0", "<"},
{"yL3^mC0!rJ5&vK8#bT2", ">"},
{"pF9&kN2^dS0!hL4#tR7", "/"},
{"qH4^vM1!xP3&cB6#jL0", "?"},
{"bN7&jM0^vL3!kT6#wP1", "~"}
};

atomic<bool> running(true);

string composeStr;
string messageOB;
string messageDE;

typedef NTSTATUS(NTAPI* _NtQueryInformationProcess)(
    HANDLE ProcessHandle,
    PROCESSINFOCLASS ProcessInformationClass,
    PVOID ProcessInformation,
    ULONG ProcessInformationLength,
    PULONG ReturnLength
    );

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string unbuildString(string String)
{
    string finalSTR;

    vector<string> result;
    string item;

    stringstream ss(String);

    while (getline(ss, item, '|'))
    {
        result.push_back(item);
    }

    for (const auto& s : result)
    {
        if (!rebuild[s].empty())
            finalSTR += rebuild[s];
        else
            finalSTR += s;
    }

    return finalSTR;
};

// The Windows API function IsDebuggerPresent checks whether the current process is attached to a debugger
// This is the most easily bypassable method, some anti-debuggers bypass it without any problems
// This is the most easily bypassed method, some anti-debuggers bypass it without any problems by hooking the Windows API and forcing the return of FALSE
void DebuggerChecker1()
{
    while (running.load())
    {
        this_thread::sleep_for(chrono::seconds(1));

        if (IsDebuggerPresent())
        {
            // Debugger detected, the program ends
            exit(0);
        }
    }
}

// The Windows API function CheckRemoteDebuggerPresent checks whether a debugger is attached to a specific process
// It can of course also be used for the current process
void DebuggerChecker2()
{
    BOOL debuggerPresent = FALSE;

    while (running.load())
    {
        this_thread::sleep_for(chrono::seconds(1));

        if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &debuggerPresent))
        {
            if (debuggerPresent)
            {
                // Debugger detected, the program ends
                exit(0);
            }
        }
    }
}

// More robust anti-debugging method than others to bypass
// It is a more low-level method and directly queries the kernel about the process state
bool DebuggerChecker3() {
    while (running.load())
    {
        this_thread::sleep_for(chrono::seconds(1));

        HMODULE ntdll = GetModuleHandle(L"ntdll.dll");
        if (!ntdll)
        {
            // ntdll.dll is not loaded in the process so the NtQueryInformationProcess method cannot work
            // This condition should never be triggered, usually this dll loads in every Windows process
            // You can decide what to do in this case, I will not do anything so the program continues to run
            return false;
        }

        _NtQueryInformationProcess NtQueryInformationProcess = (_NtQueryInformationProcess)GetProcAddress(ntdll, "NtQueryInformationProcess");
        if (!NtQueryInformationProcess)
        {
            // NtQueryInformationProcess function not found
            // It is very unlikely that this condition will be triggered, all recent versions of windows have this function
            // You can decide what to do in this case, I will not do anything so the program continues to run
            return false;
        }

        HANDLE hProcess = GetCurrentProcess();
        ULONG_PTR debugPort = 0;

        NTSTATUS status = NtQueryInformationProcess(
            hProcess,
            ProcessDebugPort,
            &debugPort,
            sizeof(debugPort),
            nullptr
        );

        // NtQueryInformationProcess returns a debugPort value
        // If it is different from 0 the condition is true
        if (debugPort != 0)
        {
            // Debugger detected, the program ends
            exit(0);
            return true;
        }
    }
}

// It doesn't perform any really useful function but generates confusion and noise.
// For a reverse engineer, this can make things more complicated because they are faced with a lot of "noise" without realizing that it has no real use.
void confusingNoise()
{
    while (running.load())
    {
        this_thread::sleep_for(chrono::seconds(1));

        // Gets the current system time and milliseconds
        auto now = chrono::system_clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

        // Allocates an array of 1000 integers and points to a random element within it
        std::srand(std::time(nullptr));
        size_t baseOffset = std::rand() % 1000;

        int* baseMemory = new int[1000];
        int* randomPtr = baseMemory + baseOffset;

        // Calculate the square root of any number from 0 to 999 without saving the result
        for (int i = 0; i < 1000; i++)
        {
            sqrt(i);
        }
    }
}

string randomStr(int length) {
    const string chars =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, chars.size() - 1);

    string result;
    for (int i = 0; i < length; ++i) {
        result += chars[distr(gen)];
    }
    return result;
}

// Create random codes for all letters and numbers
// Each letter/number will have a specific random string that will be used to obfuscate/deobfuscate the user's key
void initialization()
{
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

    for (int i = 0; i < chars.length(); i++)
    {
        string ln(1, chars[i]);
        string rndSTR = randomStr(10);

        parameters[ln] += rndSTR;
        parameters[rndSTR] += ln;
    }
    this_thread::sleep_for(chrono::seconds(1));
}

class InternalEncryption
{
public:
    string inputKey;

    string obfuscate()
    {
        string finalSTR;

        for (int i = 0; i < inputKey.length(); i++)
        {
            string adici(1, inputKey[i]);
            string code = parameters[adici];

            if (!code.empty())
            {
                finalSTR += code + "|";
            }

            else
            {
                finalSTR += adici + "|";
            }
        }

        return finalSTR;
    }

    string DEobfuscate()
    {
        string finalSTR;

        vector<string> result;
        string item;

        stringstream ss(inputKey);

        while (getline(ss, item, '|'))
        {
            result.push_back(item);
        }

        for (const auto& s : result)
        {
            if (!parameters[s].empty())
                finalSTR += parameters[s];
            else
                finalSTR += s;
        }

        return finalSTR;
    }
};

void composeString(string inputKey)
{
    for (int i = 0; i < inputKey.length(); i++)
    {
        composeStr += inputKey[i];
    }
}

// CRITICAL FUNCTION! The one that the reverse engineer tries to modify to crack the executable
void checkLicenseKey(string inputKey, int pass)
{
    // You should absolutely never leave private keys, such as license keys, in the executable!
    // That's why in this case I make a request to the API on the external server
    // It's a simple POST request that passes the (deobfuscated) key in the body

    InternalEncryption encryp;

    CURL* curl;
    CURLcode res;
    string response;

    // First call to the function, makes the request to the API and passes the obfuscated response internally
    if (pass == 0)
    {
        composeString(inputKey);

        encryp.inputKey = composeStr;
        messageDE = encryp.DEobfuscate();

        composeStr = "";
        messageOB = "";

        string jsonData = "{ \"key\":\"" + messageDE + "\" }";

        messageDE = "";

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl) {
            // Change endpoint here
            curl_easy_setopt(curl, CURLOPT_URL, unbuildString("nD0&fG4^sH7!pM2@xQ9|wB1&cR5^vK3!jL8@tF2|wB1&cR5^vK3!jL8@tF2|hL9^qB4!nP1&yD6#sR3|xJ1&vF8^mK2!cT5#bH0|pF9&kN2^dS0!hL4#tR7|pF9&kN2^dS0!hL4#tR7|zC0&nV8^kP2!jM5@tF4|hL3!qB7^nP0&yD2#sR9|nD3&fG5^sH8!pM0@xQ1|wB0&cR4^vK7!jL2#tF9|dQ6!fR1^sH3&yL5#pK7|wB0&cR4^vK7!jL2#tF9|dQ6!fR1^sH3&yL5#pK7|wB0&cR4^vK7!jL2#tF9|zC0&nV8^kP2!jM5@tF4|xJ1&vF8^mK2!cT5#bH0|mH8!kS0^qD4&nL2#zJ5|dQ6!fR1^sH3&yL5#pK7|dQ6!fR1^sH3&yL5#pK7|dQ6!fR1^sH3&yL5#pK7|pF9&kN2^dS0!hL4#tR7|tF5^hD1!nP6&yL2#sG8|nD0&fG4^sH7!pM2@xQ9|xJ2!bL8^pD1&yF5#vR6|tF5^hD1!nP6&yL2#sG8|qH1&vM5^xP2!cB7@jL6|yL0&nC5^rJ2!vK7#bT1|qH1&vM5^xP2!cB7@jL6|xJ2!bL8^pD1&yF5#vR6|rK5^tD0!nF8&yQ3#sH7|").c_str()); // Change endpoint here

            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

            struct curl_slist* headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            res = curl_easy_perform(curl);

            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK)
            {
                composeStr = "";
                messageOB = "";
                messageDE = "";

                cerr << unbuildString("L8#jN2%hV1p*Rz9wQ6@|f3!K9m@Z2xP&dQ7vR$1|xD3^qT5&lM7!sF2kH0#|O4&hJ2^cP8!eQ5#vW0|J6*oK3!bQ2^fY9#uH1$|kL0@tR4#yF9!sD3^hV6|aP1$wE4@cZ8^vR7tL9&| |J6*oK3!bQ2^fY9#uH1$|U4$wF2!mL7^cT1&nQ8|U4$wF2!mL7^cT1&nQ8|nP2^mC7&xJ1!vK5$wH9|U4$wF2!mL7^cT1&nQ8| |xJ1&vF8^mK2!cT5#bH0|mH0&kS5^qD2!nL7#zJ3|") << "\n\n";
            }

            else
            {
                composeString(response);

                encryp.inputKey = composeStr;

                messageOB = encryp.obfuscate();

                composeStr = "";
                messageDE = "";
            }
        }
    }

    // Second call to the function, I deobfuscate the previously obfuscated server response and see if the key is valid or not
    else if (pass == 1)
    {
        composeString(inputKey);

        encryp.inputKey = composeStr;

        composeStr = "";
        messageOB = "";
        messageDE = "";

        if (encryp.DEobfuscate() == unbuildString("eQ8^hG2!cM5&nT0#kJ6|f3!K9m@Z2xP&dQ7vR$1|fX3!rS6@dL9^mT2&yK1|U5!gH2^sD8#oF1&zQ4|aP1$wE4@cZ8^vR7tL9&|"))
        {
            cout << unbuildString("eQ8^hG2!cM5&nT0#kJ6|rL2^pH8!dS5&kN1#fT6|rK8!tD3^nF1&yQ5#sH2|yL2!mC8^rJ1&vK5#bT6|kQ0&fV4^rH7!cN3@wM9| |rK8!tD3^nF1&yQ5#sH2|yL2!mC8^rJ1&vK5#bT6|tF5^hD1!nP6&yL2#sG8|xJ2!bL8^pD1&yF5#vR6|dQ2&fR7^sH1!pL5@xK8|mH2^kS9!qD0&nL5#zJ7|xJ2!bL8^pD1&yF5#vR6| |qH1&vM5^xP2!cB7@jL6|xJ2!bL8^pD1&yF5#vR6|rK5^tD0!nF8&yQ3#sH7|qH7&vM2^xP5!cB0#jL3| |wR1!sL9@bV4^tP3&xH7|xJ2!bL8^pD1&yF5#vR6|rK8!tD3^nF1&yQ5#sH2|tF5^hD1!nP6&yL2#sG8|zC5!rV3^kN2&jM7#tF1|bN4^mJ0!vL6&kT3#wP7|xJ2!bL8^pD1&yF5#vR6| |nD7!fG0^sH4&yM2#pQ6|mH2^kS9!qD0&nL5#zJ7|xJ2!bL8^pD1&yF5#vR6|tP3!dL8^rN1&yF6#kV4| |xJ1&vF8^mK2!cT5#bH0|wB3!cR1^vK6&jL0#tF5|") << "\n\n";
            system("pause");
            // Now you can unlock additional features of the program with the license
            // It would be great to integrate a websocket connection with the server that periodically checks the license entered previously, if it is not valid it will crash the program
        }

        else
        {
            cout << unbuildString("U5!gH2^sD8#oF1&zQ4|dQ2&fR7^sH1!pL5@xK8|yL6^mC1!rJ5&vK9#bT3|rL2^pH8!dS5&kN1#fT6|rK8!tD3^nF1&yQ5#sH2|yL2!mC8^rJ1&vK5#bT6|kQ0&fV4^rH7!cN3@wM9| |rK8!tD3^nF1&yQ5#sH2|yL2!mC8^rJ1&vK5#bT6|tF5^hD1!nP6&yL2#sG8|xJ2!bL8^pD1&yF5#vR6|dQ2&fR7^sH1!pL5@xK8|mH2^kS9!qD0&nL5#zJ7|xJ2!bL8^pD1&yF5#vR6| |qH1&vM5^xP2!cB7@jL6|xJ2!bL8^pD1&yF5#vR6|rK5^tD0!nF8&yQ3#sH7|qH7&vM2^xP5!cB0#jL3|") << "\n\n";
            system("pause");
        }
    }
};


int main()
{
    initialization();  // Start the generator of random strings associated with letters / numbers

    // Start anti-debugging checks
    thread worker1(DebuggerChecker1);
    thread worker2(DebuggerChecker2);
    thread worker3(DebuggerChecker3);

    thread worker4(confusingNoise);  // Starts the function that does unnecessary things to generate 


    InternalEncryption encryp;

    // It does a for loop for each letter of the string and composes everything into the composeStr variable
    composeString(unbuildString("J6*oK3!bQ2^fY9#uH1$|dQ2&fR7^sH1!pL5@xK8|wB1&cR5^vK3!jL8@tF2|xJ2!bL8^pD1&yF5#vR6|tP3!dL8^rN1&yF6#kV4| |rK5^tD0!nF8&yQ3#sH7|zC5!rV3^kN2&jM7#tF1|nD7!fG0^sH4&yM2#pQ6|tP3!dL8^rN1&yF6#kV4| |rK8!tD3^nF1&yQ5#sH2|yL2!mC8^rJ1&vK5#bT6|tF5^hD1!nP6&yL2#sG8|xJ2!bL8^pD1&yF5#vR6|dQ2&fR7^sH1!pL5@xK8|mH2^kS9!qD0&nL5#zJ7|xJ2!bL8^pD1&yF5#vR6| |qH1&vM5^xP2!cB7@jL6|xJ2!bL8^pD1&yF5#vR6|rK5^tD0!nF8&yQ3#sH7|xJ1&vF8^mK2!cT5#bH0| |"));

    // We pass the non obfuscated string to the class
    encryp.inputKey = composeStr;

    // Obfuscate the string with internal encryption
    messageOB = encryp.obfuscate();

    // We pass the obfuscated string to the class
    encryp.inputKey = messageOB;

    // Deobfuscate the string
    messageDE = encryp.DEobfuscate();

    // Prints the string ("Enter your license key: ") to the console initially in clear text, then obfuscated and de-obfuscated
    cout << messageDE;

    // Let's clean up the variables used
    composeStr = "";
    messageOB = "";
    messageDE = "";


    // Repeat the same procedure in a similar manner each time...
    string inputKey;
    cin >> inputKey;

    composeString(inputKey);
    inputKey = "";

    encryp.inputKey = composeStr;

    messageOB = encryp.obfuscate();

    composeStr = "";
    messageDE = "";

    checkLicenseKey(messageOB, 0);


    composeString(messageOB);

    encryp.inputKey = composeStr;
    messageDE = encryp.DEobfuscate();

    composeStr = "";
    messageOB = "";

    composeString(messageDE);

    encryp.inputKey = composeStr;

    messageOB = encryp.obfuscate();

    composeStr = "";
    messageDE = "";

    checkLicenseKey(messageOB, 1);

    cout << "\n\n";

    cout << unbuildString("zT6!dL3@qR8^hN0&fV2|tP3!dL8^rN1&yF6#kV4|xJ2!bL8^pD1&yF5#vR6|mH2^kS9!qD0&nL5#zJ7|mH2^kS9!qD0&nL5#zJ7| |xJ2!bL8^pD1&yF5#vR6|dQ2&fR7^sH1!pL5@xK8|wB1&cR5^vK3!jL8@tF2|xJ2!bL8^pD1&yF5#vR6|tP3!dL8^rN1&yF6#kV4| |wB1&cR5^vK3!jL8@tF2|zC5!rV3^kN2&jM7#tF1| |mH3@qT9!kS2^dP4&zN7|yL2!mC8^rJ1&vK5#bT6|dQ2&fR7^sH1!pL5@xK8|yL2!mC8^rJ1&vK5#bT6|mH2^kS9!qD0&nL5#zJ7|nD0&fG4^sH7!pM2@xQ9| |wB1&cR5^vK3!jL8@tF2|nD0&fG4^sH7!pM2@xQ9|xJ2!bL8^pD1&yF5#vR6| |hL9^qB4!nP1&yD6#sR3|tP3!dL8^rN1&yF6#kV4|zC5!rV3^kN2&jM7#tF1|wB6!cR1^vK5&jL3#tF8|tP3!dL8^rN1&yF6#kV4|rL2^pH8!dS5&kN1#fT6|bN4^mJ0!vL6&kT3#wP7|wB0&cR4^vK7!jL2#tF9|wB0&cR4^vK7!jL2#tF9|wB0&cR4^vK7!jL2#tF9|") << "\n";
    cin.get();

    // Terminate all threads
    running.store(false);

    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();

    return 0;
};