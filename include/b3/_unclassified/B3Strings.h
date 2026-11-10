// CB3Strings / EGlobalStrings -- declarations only, as call targets. Folder: _unclassified/ (docs/conventions.md:
// the E map names the file B3Strings.cpp, but no evidence of its Area yet).
#ifndef B3_B3STRINGS_H
#define B3_B3STRINGS_H

// [C] type name from CB3HeadingComponent::Prepare(EGlobalStrings, EHeadingType)'s demangled name in the
// E-build maps (research/E_dnat_symbols.csv); enumerators unknown. Converted to int for GetString.
enum EGlobalStrings {};

class CB3Strings {
public:
    // 0x00271A00 [L]: name from research/names_C_retail.csv (B3Strings.cpp, "inferred" boundary match).
    // 8 bytes: tail-calls func_00271A60 with this->field_0. Returns the string (used as const unsigned
    // short* by its callers [C]; the return type itself isn't in the mangled name).
    const unsigned short *GetString(int);
};

#endif
