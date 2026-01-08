# 739. Daily Temperatures

## 1) Problemi açıklaması
   - Amaç: Günlük sıcaklık dizisi verilmiş. Her gün için, daha sıcak bir günün kaç gün sonra geleceğini bulmak.
   - Eğer gelecekte daha sıcak gün yoksa --> 0
   - Sadece sonraki günlere bakacağız. (geçmişe bakmayacağız)
   - En yakın daha sıcak günü arıyoruz.
     
## 2) Örnek

Verilen dizi = ` [73, 74, 75, 71, 69, 72, 76, 73] `

Index: 0   1   2   3   4   5   6   7
Temp:  73  74  75  71  69  72  76  73
Wait:  1   1   4   2   1   1   0   0

Her eleman için sağdaki tüm elemanları taramalıyız : O(n^2)

## 3) Algoritma

1. result[] dizisi oluşturulur. (En başta tüm elemanları 0)
2. stack oluşturulur (index'leri tutacak)
3. Her gün için soldan sağa:
   a) Stack kontrolü:
      WHILE stack boş değil VE (temperature[stack.pop] < temperature[current])
         index = stack.pop()
         result[index] = current - index
   
   b) Mevcut indexi stack'e ekle.
      stack.push(current)

4. Stackte kalanlar için result zaten 0
5. return result[]

` [30,40,50,60] ` örneğini inceleyelim:
```text
1.Adım --> i=0, temp=30
   stack: [] --> [0]
   result: [0, 0, 0, 0]

2.Adım --> i=1, temp=40
   40>30 olduğu için 0 indexini stackten çıkarmalıyız. result[0] = 1-0 = 1
   Stack: [0] ---> [] ---> [1]
   result: [1, 0, 0, 0]

3.Adım --> i=2, temp=50
   50>40 olduğu için 1 indexini stackten çıkarmalıyız. result[1] = 2-1 = 1
   Stack: [1] ---> [] ---> [2]
   result: [1, 1, 0, 0]

4.Adım --> i=3, temp=60
   60>50 olduğu için 2 indexini stackten çıkarmalıyız. result[2] = 3-2 = 1
   stack: [2] ---> [] ---> [3]
   result: [1, 1, 1, 0]

Stackte kalan [3] ---> result[3] = 0 (zaten var)
Cevap : [1, 1, 1, 0]
```

` [73, 74, 75, 71, 69, 72, 76, 73] ` örneğini inceleyelim:
```text
i=0, temp=73
               stack: [] ---> [0]
               result : [0, 0, 0, 0, 0, 0, 0, 0]
               
i=1, temp=74
               74 > 73. i=0'ı stackten çıkar. result[0] = 1-0 = 1
               stack: [0] ---> [] ---> [1]
               result: [1, 0, 0, 0, 0, 0, 0, 0]
               
i=2, temp=75
               75 > 74. i=1'i stackten çıkar. result[1] = 2-1 = 1
               stack: [1] ---> [] ---> [2]
               result: [1, 1, 0, 0, 0, 0, 0, 0]
               
i=3, temp=71
               71 < 75 olduğu için  i=2 stackte kalıyor. Yanına i=3 'ü ekliyoruz. 
               stack: [2] ---> [2, 3]
               result: [1, 1, 0, 0, 0, 0, 0, 0]

i=4, temp=69
               69 < 71 olduğu için i=3 stackte kalıyor. Yanına i=4'ü ekliyoruz.
               stack: [2, 3] ---> [2, 3, 4]
               result: [1, 1, 0, 0, 0, 0, 0, 0]
               
i=5, temp=72
               72 > 69 olduğu için i=4'ü stackten çıkarıyoruz. result[4] = 5 - 4 = 1
               72 > 71 olduğu için i=3'ü stackten çıkarıyoruz. result[3] = 5 - 3 = 2
               72 < 75 olduğu için i=2 kalıyor. Yanına i=5'i ekliyoruz.
               stack: [2, 3, 4] ---> [2, 5]
               result: [1,1,0,2,1,0,0,0]

i=6, temp=76
               76 > 72 olduğu için i=5'i stackten çıkarıyoruz. result[5] = 6 - 5 = 1
               76 > 75 olduğu için i=2'yi stackten çıkarıyoruz. result[2] = 6 - 2 = 4
               stack: [2, 5] ---> [] ---> [6]
               result: [1,1,4,2,1,1,0,0]
               
i=7, temp=73
               73 < 76 olduğu için i=6 stackte kalıyor. Yanına i=7'yi ekliyoruz.
               stack: [6] ---> [6, 7]
               result: [1,1,4,2,1,1,0,0]
```

## NOTLAR:
1) Stackte ne tutuyoruz ? Indexleri. (Değerleri değil)
2) Neden indexleri tutuyoruz ? Fark hesabı için. (i - prevIndex bize gün hesabı yapacak)
3) Monotonic Neden ? Küçükten büyüğe sıra, büyük gelince küçüklerin cevabı bulunur.
4) Kalan elemanlar ne olacak ? Stackte kalanlar için cevap 0. (Başlangıçta 0 ile initialize etmiştik)


