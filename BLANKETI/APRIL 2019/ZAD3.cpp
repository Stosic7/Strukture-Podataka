int BSTreeInt::countLeaves(int index) {
    if (index >= size || tree[index] == -1) {
        return 0; // Nevažeći čvor
    }
    // Proveravamo da li je čvor list
    if (2 * index + 1 >= size || tree[2 * index + 1] == -1) { // leva deca
        if (2 * index + 2 >= size || tree[2 * index + 2] == -1) { // desna deca
            return 1; // čvor je list
        }
    }
    // Rekurzivno brojimo listove u levoj i desnoj podstablo
    return countLeaves(2 * index + 1) + countLeaves(2 * index + 2);
}

// Funkcija koja vraća broj listova
int BSTreeInt::LeavesCount() {
    return countLeaves(0); // Počinjemo od korena (index 0)
}
