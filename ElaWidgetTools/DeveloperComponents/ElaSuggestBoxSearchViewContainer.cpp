#include "ElaSuggestBoxSearchViewContainer.h"

#include <QPainter>

#include "ElaTheme.h"
ElaSuggestBoxSearchViewContainer::ElaSuggestBoxSearchViewContainer(QWidget* parent)
    : QWidget{parent}
{
    setContentsMargins(8, 2, 8, 8);
    setObjectName("ElaSuggestBoxSearchViewBaseWidget");
    setStyleSheet("#ElaSuggestBoxSearchViewBaseWidget{background-color:transparent}");
    _themeMode = eTheme->getThemeMode();
    connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode themeMode) { _themeMode = themeMode; });
}

ElaSuggestBoxSearchViewContainer::~ElaSuggestBoxSearchViewContainer()
{
}

void ElaSuggestBoxSearchViewContainer::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.save();
    painter.setRenderHints(QPainter::Antialiasing);
    eTheme->drawEffectShadow(&painter, rect(), 4, 2);
    painter.setPen(ElaThemeColor(_themeMode, PopupBorder));
    painter.setBrush(ElaThemeColor(_themeMode, PopupBase));
    QRect foregroundRect(6, 0, rect().width() - 2 * 6, rect().height() - 6);
    painter.drawRoundedRect(foregroundRect, 2, 2);
    painter.restore();
}
