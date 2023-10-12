from Utils import *
import requests
import json

# Updates ~merged.txt file under editorial directory
# This file is used by LeetHelp extension
def updateMergedFile():
    cppFiles = map(basename, glob(f"**/*{CPP_EXTENSION}", recursive=True))
    slugs = list(map(extractSlugFromCppFile, cppFiles))
    slugs.sort()
    urls = map(buildUrlBySlug, slugs)

    content = "\n".join(urls)
    with open(join(CURRENT_PATH, EDITORIAL_DIR, "~merged.txt"), "w") as f:
        f.write(content)

    print(PASSED, f"Updated {MERGED_FILENAME}")

# Updates ~all.txt file under editorial directory
# This file is used by SelectRandomUnsolvedProblem script
def getProblems():
    url = "https://leetcode.com/graphql/"

    payload = "{\"query\":\"\\n    query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {\\n  problemsetQuestionList: questionList(\\n    categorySlug: $categorySlug\\n    limit: $limit\\n    skip: $skip\\n    filters: $filters\\n  ) {\\n    total: totalNum\\n    questions: data {\\n      difficulty\\n      titleSlug\\n    }\\n  }\\n}\\n    \",\"variables\":{\"categorySlug\":\"\",\"skip\":0,\"limit\":9999999,\"filters\":{}}}"
    headers = {
    'authority': 'leetcode.com',
    'accept': '*/*',
    'content-type': 'application/json',
    'origin': 'https://leetcode.com',
    'referer': 'https://leetcode.com/problemset/all/',
    'sec-fetch-dest': 'empty',
    'sec-fetch-mode': 'cors',
    'sec-fetch-site': 'same-origin',
    }

    response = requests.request("POST", url, headers=headers, data=payload)

    r = json.loads(response.text)
    problems_array = r["data"]["problemsetQuestionList"]["questions"]
    extractSlugAndDifficulty = lambda x: x["titleSlug"] + "," + x["difficulty"]
    problems = list(map(extractSlugAndDifficulty, problems_array))
    problems.sort()

    with open(join(CURRENT_PATH, EDITORIAL_DIR, ALL_FILENAME), "w") as f:
        f.write("\n".join(problems))
    print(PASSED, f"Saved all {len(problems)} problems")


if __name__ == "__main__":
    checkPath()
    getProblems()
    updateMergedFile()
