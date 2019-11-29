bool tryParse (const std::string& inputString, int& outputNumber) {

    std::istringstream iss(inputString);

    if (iss >> outputNumber) {
        return true;
    } else {
        return false;
    }
}
