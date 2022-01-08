
#include <FaBoLCD_PCF8574.h> //lcd çalışması için gerekli library
#include <Wire.h> /*Arduino'nun I2C özelliği kullanılıyor bu nedenle bu library gerekli*/

#include <DHT.h>
// toplamda 3 tane kütüphane kullanıldı
//kullanılacak sensör ve ekranın tanımlanması gerekiyor
#define DHTPIN 2 //sıcaklık sensörü 2 numaralı pine takıldı
#define DHTTYPE DHT11 //benim kullandığım DHT tipi 11 başka tipler de bulunduğundan bunu belirttim

DHT dht(DHTPIN, DHTTYPE); //DHT isminde belirtilen pin ve modele sahip bir obje oluşturdum

FaBoLCD_PCF8574 lcd; //lcd ekran tanımlandı


void setup() {
  pinMode(7,OUTPUT);
  
  lcd.begin(16,2); //lcd 16 satır 2 sütundan oluşuyor bu satırda lcd başlatıldı
  lcd.print("   THERMOMETER");
  delay(1000); /* 1000 milisaniye boyunca bu yazı ekranda okunacak*/
  dht.begin(); //dht sensörünün başlatıldı

}

void loop() {
//sensörden verilerin okunup yazdırılmasını buradaki kodlar sağlar
  float temp = dht.readTemperature(); //sıcaklık ölçülür ve temp isimli değişkene eşitlenir 
  float hum = dht.readHumidity(); //nem değeri ölçülür hum değerine eşitlenir
//daha iyi bir ölçüm için bu iki değer float değeri olarak tanımlandı 
  lcd.clear();

  lcd.setCursor(0,0); //lcd'de kareler 0,0 noktasından başlar ilk kareden yazılmaya başlanmasını istediğim için bu nokta belirtildi
  //ilk değer sütunu ikinci değer satırı belirtir
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
//ilk satıra sıcaklık değeri yazılması istendiğinden "sicaklik" ayrıca belirtildi
  lcd.setCursor(0,1);
  lcd.print("Humidity: %");
  lcd.print(hum);
//nemin ikinci satıra yazılması isteniyor ayrıca dht11 nemin % kaç olduğunu ölçer bu değerlerin karışmaması için "nem" ayrıca belirtildi
  delay(3000);
//değerlerin 3 saniyede bir güncellenmesi için 3000 gecikme 3000 mili saniye olarak belirlendi

if (temp>30){
  lcd.setCursor(0,0); 
  lcd.print("HIGH   Temp! ");
  delay(3000);
  
  digitalWrite(7,HIGH);
 
}
if (temp<20){
  lcd.setCursor(0,0); 
  lcd.print("LOW   Temp! ");
  delay(3000);
  
  digitalWrite(7,HIGH);
 
}
if (hum<50){
  lcd.setCursor(0,1); 
  lcd.print("LOW   HUMIDITY! ");
  delay(3000);
  
  digitalWrite(7,HIGH);
  
}
if (hum>90){
  lcd.setCursor(0,1); 
  lcd.print("   HIGH HUMIDITY! ");
  delay(3000);
  
  digitalWrite(7,HIGH);
  
}
else {
(7,LOW);




}
}
