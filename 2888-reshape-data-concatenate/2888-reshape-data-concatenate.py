import pandas as pd

def concatenateTables(df1, df2) -> pd.DataFrame:
    return pd.concat([df1,df2])
    
