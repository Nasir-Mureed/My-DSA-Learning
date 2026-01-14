import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    # return students[ ~students["name"].isna()]
    students.dropna(subset="name",inplace=True)
    return students
