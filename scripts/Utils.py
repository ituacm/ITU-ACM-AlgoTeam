from os import getcwd
from os.path import join, basename
from glob import glob

###########################################
#                CONSTANTS                #
###########################################
CURRENT_PATH = getcwd()
LEETCODE_BASE_URL = "https://leetcode.com/"
EDITORIAL_DIR = "Regular-Question-Answers"
CPP_EXTENSION = ".cpp"
MERGED_FILENAME = "~merged.txt"
ALL_FILENAME = "~all.txt"
PASSED = "[PASSED]"
FAILED = "[FAILED]"

###########################################
#                FUNCTIONS                #
###########################################

buildUrlBySlug = lambda slug: f"{LEETCODE_BASE_URL}problems/{slug}/"

extractSlugFromURL = lambda url: url.split("/")[4]

extractSlugFromCppFile = lambda cppFile: cppFile[:-len(CPP_EXTENSION)]

# Finds url in the given file and returns it
def extractUrlFromFile(filename: str):
    with open(join(CURRENT_PATH, EDITORIAL_DIR, filename)) as f:
        while True:
            line = f.readline().strip()
            start_index = line.find(LEETCODE_BASE_URL)
            if start_index != -1:
                return line[start_index:]

            # end of file
            if not line:
                return None

def checkPath():
    # check the current path is correct
    isPathCorrect = len(glob(EDITORIAL_DIR)) == 1
    if not isPathCorrect:
        print(FAILED, "Please run this script inside root of the repository...")
        exit()
