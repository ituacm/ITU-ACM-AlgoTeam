from Utils import *

###########################################
#                  TESTS                  #
###########################################

# Finds all the .cpp files inside repository
# Validates that they are under the editorial directory
def checkPathOfAllCppFiles():
    allCppFiles = glob(f"**/*{CPP_EXTENSION}", recursive=True)
    wrongPlacedCppFiles = list(filter(lambda f: not f.startswith(EDITORIAL_DIR), allCppFiles))
    if len(wrongPlacedCppFiles) == 0:
        print(PASSED, f"All {CPP_EXTENSION} files are under the {EDITORIAL_DIR}")
    else:
        print(FAILED, f"These {CPP_EXTENSION} files are not under the {EDITORIAL_DIR}:")
        print("\n".join(wrongPlacedCppFiles))
        exit()

# Checks all the cpp files under editorial directory
# Validates leetcode slug and the filename
def validateCppFilenamesAndSlugs():
    cppFiles = map(basename, glob(f"**/*{CPP_EXTENSION}", recursive=True))

    allWellFormed = True
    for cppFile in cppFiles:
        url = extractUrlFromFile(cppFile)
        if url:
            slug = extractSlugFromURL(url)
        if not url or not slug or slug + CPP_EXTENSION != cppFile:
            allWellFormed = False
            print(FAILED, f"Error (LeetCode slug in the url and filename not matched).")
            print(f"File: ./{EDITORIAL_DIR}/{cppFile}")

    if allWellFormed:
        print(PASSED, "All files are well formed (filename and its url appropiate)")
    else:
        exit()

if __name__ == "__main__":
    checkPath()
    checkPathOfAllCppFiles()
    validateCppFilenamesAndSlugs()
