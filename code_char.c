int code_char(arbre *a, char c, encodage **e) {
    if (a == NULL) return 0;
    if (est_feuille(a)) {
        if (a->data == c) return 1;
        return 0;
    }
    if (code_char(a->gauche, c, e)) {
        encodage *n = malloc(sizeof(encodage));
        n->data = 0;
        n->suivant = *e;
        *e = n;
        return 1;
    }
    if (code_char(a->droite, c, e)) {
        encodage *n = malloc(sizeof(encodage));
        n->data = 1;
        n->suivant = *e;
        *e = n;
        return 1;
    }
    return 0;
}
