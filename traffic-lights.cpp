#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// Interrupt bayrağı
std::atomic<bool> interrupted(false);

// Interrupt durumu kontrol fonksiyonu
void checkInterrupt()
{
    if (interrupted)
    {
        std::cout << "Interrupt Yakalandı!" << std::endl;
        // Burada interrupt işlemleri gerçekleştirilebilir.
        // Örneğin: Acil durum işlemleri, kaynak serbest bırakma, vs.
        interrupted = false; // Interrupt işlemi tamamlandıktan sonra tekrar başlamak için sıfırla
    }
}

// Trafik lambası gösterme fonksiyonu
void showTrafficLight(const std::string& color)
{
    std::cout << "Traffic Light: " << color << std::endl;
    checkInterrupt(); // Her durumda interrupt kontrolü yap
}

// Trafik lambası simülasyonu
void trafficLightSimulation()
{
    while (!interrupted) // interrupted true olunca döngüden çık
    {
        showTrafficLight("Red");
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 2 saniye beklet

        showTrafficLight("Yellow");
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 saniye beklet

        showTrafficLight("Green");
        std::this_thread::sleep_for(std::chrono::seconds(2)); // 2 saniye beklet
    }
}

// Interrupt tetikleyen fonksiyon
void triggerInterrupt()
{
    std::cout << "Interrupt Triggered!" << std::endl;
    interrupted = true;
}

int main()
{
    std::cout << "Trafik Lambası Simülasyonu Başlıyor..." << std::endl;

    // Trafik lambası simülasyonunu başlat
    std::thread simulationThread(trafficLightSimulation);

    // Interrupt tetikleyiciyi başlat
    std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniye beklet
    triggerInterrupt();
    // Ana program, trafik lambası simülasyonunun tamamlanmasını bekler
    simulationThread.join();
    return 0;
}