#pragma once
#include <QObject>
#include "led.h"

class LedController : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool on READ isOn NOTIFY onChanged)
    Q_PROPERTY(bool switchPressed READ switchPressed NOTIFY switchChanged)
   public:
    explicit LedController(QObject* parent=nullptr);

    Q_INVOKABLE void setOn(bool on);
    Q_INVOKABLE void toggleFromSwitch(); // calls task.act_on_led()
    Q_INVOKABLE bool refreshSwitch();    // polls switch into property

    bool isOn() const { return m_on; }
    bool switchPressed() const { return m_switch; }

   signals:
    void onChanged();
    void switchChanged();

   private:
    Task m_task;
    bool m_on=false;
    bool m_switch=false;
};
