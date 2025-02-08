#ifndef ELAPROMOTIONVIEW_H
#define ELAPROMOTIONVIEW_H

#include <QPixmap>
#include <QWidget>

#include "stdafx.h"
class ElaPromotionCard;
class ElaPromotionViewPrivate;
class ELA_EXPORT ElaPromotionView : public QWidget
{
    Q_OBJECT
    Q_Q_CREATE(ElaPromotionView)
    Q_PROPERTY_CREATE_Q_H(int, CardExpandWidth)
    Q_PROPERTY_CREATE_Q_H(int, CardCollapseWidth)
    Q_PROPERTY_CREATE_Q_H(int, CurrentIndex)
    Q_PROPERTY_CREATE_Q_H(bool, IsAutoScroll)
    Q_PROPERTY_CREATE_Q_H(int, AutoScrollInterval)
public:
    explicit ElaPromotionView(QWidget* parent = nullptr);
    ~ElaPromotionView();

    [[nodiscard]]size_t leftPadding() noexcept;
    void setLeftPadding(size_t value) noexcept;
    void appendPromotionCard(ElaPromotionCard* card);
    ElaPromotionCard* getPromotionCard(int index) noexcept;
protected:
    virtual void wheelEvent(QWheelEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
};

#endif // ELAPROMOTIONVIEW_H
