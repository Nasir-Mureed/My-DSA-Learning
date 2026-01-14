import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=["student_id", "age"])
 
    
    
    
    
    #pd.DataFrame({"student_id":student_data[0],"age":student_data[1]})
    