#ifndef FACTORY_H
#define FACTORY_H

#include "Product.h"

// 抽象工厂
class IFactory
{
public:
    enum FACTORY_TYPE {
        BENZ_FACTORY,   // 奔驰工厂
        BMW_FACTORY,    // 宝马工厂
        AUDI_FACTORY    // 奥迪工厂
    };

    virtual ~IFactory(){}
    virtual ICar     * CreateCar()  = 0;                        // 生产汽车
    virtual IBike    * CreateBike() = 0;                        // 生产自行车
    static  IFactory * CreateFactory( FACTORY_TYPE factory );   // 创建工厂
};

// 奔驰工厂
class BenzFactory : public IFactory
{
public:
    ICar* CreateCar() {
        return new BenzCar();
    }

    IBike* CreateBike() {
        return new BenzBike();
    }
};

// 宝马工厂
class BmwFactory : public IFactory
{
public:
    ICar* CreateCar() {
        return new BmwCar();
    }

    IBike* CreateBike() {
        return new BmwBike();
    }
};

// 奥迪工厂
class AudiFactory : public IFactory
{
public:
    ICar* CreateCar() {
        return new AudiCar();
    }

    IBike* CreateBike() {
        return new AudiBike();
    }
};

// 创建工厂
IFactory * IFactory::CreateFactory( FACTORY_TYPE factory )
{
    IFactory *pFactory = nullptr;
    switch ( factory ) {
    case FACTORY_TYPE::BENZ_FACTORY:    // 奔驰工厂
        pFactory = new BenzFactory();
        break;
    case FACTORY_TYPE::BMW_FACTORY:     // 宝马工厂
        pFactory = new BmwFactory();
        break;
    case FACTORY_TYPE::AUDI_FACTORY:    // 奥迪工厂
        pFactory = new AudiFactory();
        break;
    default:
        break;
    }

    return pFactory;
}

#endif // FACTORY_H
