import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    tp=players.shape
    return [tp[0], tp[1]]