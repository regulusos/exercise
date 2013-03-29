#!/usr/bin/env python
 
import gtk
import os
import pango
import pexpect
import pygtk 
pygtk.require('2.0')

CA_KEY     = "/home/panhaitao/ca/ca.key"
CA_CRT     = "/home/panhaitao/ca/ca.crt"
CA_CONFIG  = "/home/panhaitao/ca/openssl.cnf"

class app_ui(object):
	def __init__(self):
		self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
		self.window.set_title("CA Manager Center")
		self.window.set_size_request(800, 480)
		self.window.set_border_width(8)
		self.window.set_position(gtk.WIN_POS_CENTER)
		self.window.connect("delete_event", self.delete_event)
		self.window.connect("destroy", self.destroy)
		
		self.button_quit = gtk.Button("Quit")
		self.button_quit.connect("clicked", self.hello, None)
		self.button_quit.connect_object("clicked", gtk.Widget.destroy, self.window)

		self.button_ca = gtk.Button("ca")
		self.button_client_create= gtk.Button("client_create")
		self.button_client_show= gtk.Button("ca_show")
		
		self.button_submit = gtk.Button("submit")
		self.button_reset = gtk.Button("reset")

		self.table = gtk.Table(10, 5, True)
		self.window.add(self.table)

		self.table.attach(self.button_ca, 0, 1, 0, 1)
		self.table.attach(self.button_client_create, 0, 1, 1, 2)
		self.table.attach(self.button_client_show, 0, 1, 2, 3)
		self.table.attach(self.button_quit, 0, 1, 3, 4)

		self.fixed = gtk.Fixed()
		self.table.attach(self.fixed, 1, 9, 0, 5)
		
		for i in range(1, 8):
			self.entry = gtk.Entry(max=0)
			self.fixed.put(self.entry, 350, i*50)
			self.entry.show()


		self.fixed.put(self.button_submit, 350, 400)
		self.fixed.put(self.button_reset, 430, 400)

		self.button_submit.connect("clicked", self.enter_callback, self.entry)
		
		self.button_submit.show()
		self.button_reset.show()

		self.button_quit.show()
		self.button_ca.show()
		self.button_client_create.show()
		self.button_client_show.show()

			
		self.fixed.show()
		self.table.show()
		self.window.show()

	def enter_callback(self, widget, entry):
		entry_common_name = entry.get_text()
		print "Entry contents: %s\n" % entry_common_name

		child = pexpect.spawn('openssl req -new -x509 -days 3650 -key %s -out %s -extensions v3_ca -config %s '%(CA_KEY, CA_CRT, CA_CONFIG))
		child.sendline ('\n')
		child.sendline ('\n')
		child.sendline ('\n')
		child.sendline ('\n')
		child.sendline ('\n')
		child.sendline ('%s' %(entry_common_name))
		child.sendline ('\n')

	def hello(self, widget, data=None):
		print "Hello World"
	def delete_event(self, widget, event, data=None):
		print "delete event occurred"
		return False

	def destroy(self, widget, data=None):
		gtk.main_quit()
	def main(self):
		gtk.main()

if __name__ == "__main__":	
	ca_create = app_ui()
	ca_create.main()
