chooseWhichOnBoat()
> 一開始先隨機選取要取一個還是取兩個
> 並判斷是不是是不是跟船是在同一側
> 再判斷是否有沒有🐔跟🐭，或是🐶根🐔同時被選到
> 如果都true就return true
> 如果不是就continue回去重新取

shipMove()
> （這時候的狀態，一定會有IDLE）
> 先把shipPos移到另一邊
> 在把IDLE狀態的移到跟shipPos同一邊

---
---
用這兩個函式不停地去跑，等到有三個LEFT就break，並輸出成String在answer變數內

但是會有跑不下去的情況（程式碼會卡住），

故設定一個count去判斷，若執行超過100次就回傳false，並reset()去初始化參數