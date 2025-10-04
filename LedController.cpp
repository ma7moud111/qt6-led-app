#include "LedController.h"

LedController::LedController(QObject* p): QObject(p) {}

void LedController::setOn(bool on) {
    bool ok = on ? m_task.set_gpio_high() : m_task.set_gpio_low();
    if (ok && m_on != on) { m_on = on; emit onChanged(); }
}

void LedController::toggleFromSwitch() {
    bool ok = m_task.act_on_led();
    if (ok) {
        // best effort: update from hardware if you have a getter, else flip
        m_on = !m_on;
        emit onChanged();
    }
}

bool LedController::refreshSwitch() {
    bool v = m_task.get_switch_value();
    if (v != m_switch) { m_switch = v; emit switchChanged(); }
    return v;
}
