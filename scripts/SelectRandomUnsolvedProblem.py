from Utils import *
from random import randint

def getSolvedSlugs():
    solvedSlugs = None
    with open(join(CURRENT_PATH, EDITORIAL_DIR, MERGED_FILENAME)) as f:
        solvedSlugs = [extractSlugFromURL(s.strip()) for s in f.readlines()]
    return solvedSlugs

def getAllUnsolved():
    allSlugsAndDifficulties = None
    with open(join(CURRENT_PATH, EDITORIAL_DIR, ALL_FILENAME)) as f:
        allSlugsAndDifficulties = [s.strip().split(",") for s in f.readlines()]
    return allSlugsAndDifficulties

if __name__ == "__main__":
    solved = getSolvedSlugs()
    all = getAllUnsolved()

    solved_i = 0
    all_i = 0
    while solved_i < len(solved) and all_i < len(all):
        solved_slug = solved[solved_i]
        all_slug = all[all_i][0]
        if solved_slug < all_slug:
            solved_i += 1
        elif solved_slug == all_slug:
            all[all_i].append(False)
            solved_i += 1
            all_i += 1
        else:
            all[all_i].append(True)
            all_i += 1
    if all_i < len(all):
        while all_i < len(all):
            all[all_i].append(True)
            all_i += 1

    unsolved = list(filter(lambda p: p[2], all))
    easy = [p[0] for p in filter(lambda p: p[1] == "Easy", unsolved)]
    medium = [p[0] for p in filter(lambda p: p[1] == "Medium", unsolved)]
    hard = [p[0] for p in filter(lambda p: p[1] == "Hard", unsolved)]

    print(f"There are {len(easy)} easy, {len(medium)} medium and {len(hard)} hard problems that not solved yet...")

    while True:
        print("\n\nSelect Random Question:\n(e) easy\n(m) medium\n(h) hard\n(q) quit\n>>> ", end="")
        s = input().strip().lower()
        if s == "e":
            print(buildUrlBySlug(easy[randint(0, len(easy) - 1)]))
        elif s == "m":
            print(buildUrlBySlug(medium[randint(0, len(medium) - 1)]))
        elif s == "h":
            print(buildUrlBySlug(hard[randint(0, len(hard) - 1)]))
        elif s == "q":
            print("Selected Quit...")
            exit()
        else:
            print("Input is not valid!")
