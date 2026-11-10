// Hand-written; the lifter refused it (switch: 8,12,20 true; case 0/default last).

extern "C" bool ShouldWeEncryptMessageContents__17CB3NetworkManagerFi(int p)
{
    switch (p) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9: case 10: case 11: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        return false;
    case 8:
    case 12:
    case 20:
        return true;
    case 0:
    default:
        return false;
    }
}
