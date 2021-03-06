/**
 * Copyright 2020 Hatchbed L.L.C.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LOG_VIEW_STATUS_PANEL_H_
#define LOG_VIEW_STATUS_PANEL_H_

#include <log_view/panel_interface.h>
#include <log_view/log_store.h>

namespace log_view {

class StatusPanel : public PanelInterface {
  public:
  StatusPanel(int height, int width, int y, int x, LogStorePtr& logs) : PanelInterface(height, width, y, x), logs_(logs) {}
  virtual ~StatusPanel() {}
  virtual void refresh();

  virtual void setConnected(bool connected) { connected_ = connected; }
  virtual void setRosTime(const ros::Time& time) { ros_time_ = time; }
  virtual void setSystemTime(const ros::WallTime& time) { system_time_ = time; }

  protected:
  bool connected_ = false;
  ros::Time ros_time_ = ros::Time(0);
  ros::WallTime system_time_ = ros::WallTime(0);
  LogStorePtr logs_;
};
typedef std::shared_ptr<StatusPanel> StatusPanelPtr;

}  // namespace log_view

#endif  // LOG_VIEW_STATUS_PANEL_H_