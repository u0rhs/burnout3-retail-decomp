// CB3HUD::IsDoingTransition() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool return: `return field_0 != -1.0f;`).

class CB3HUD {
public:
    bool IsDoingTransition();
    float field_0;
};
bool CB3HUD::IsDoingTransition()
{
    return field_0 != -1.0f;
}
