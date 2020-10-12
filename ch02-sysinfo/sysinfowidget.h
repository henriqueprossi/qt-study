#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = nullptr,
                           int start_delay_ms = 500,
                           int update_series_delay_ms = 500);

protected:
    QtCharts::QChartView& chart_view();

protected slots:
    virtual void update_series() = 0;

private:
    QTimer m_refresh_timer;
    QtCharts::QChartView m_chart_view;

signals:

};

#endif // SYSINFOWIDGET_H
