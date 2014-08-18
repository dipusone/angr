import threading

import rpyc
from rpyc.utils.server import ThreadedServer

class AngrServer(threading.Thread):
    def __init__(self, active_projects={}, active_surveyors={}, port=1234, host='localhost'):
        super(AngrServer, self).__init__()
        self.port = port
        self.host = host
        class AngrService(rpyc.Service):
            exposed_projects = active_projects
            exposed_surveyors = active_surveyors

            def on_connect(self):
                self._conn._config.update(dict(
                    allow_all_attrs = True,
                    allow_pickle = True,
                    allow_getattr = True,
                    allow_setattr = True,
                    allow_delattr = True,
                    import_custom_exceptions = True,
                    instantiate_custom_exceptions = True,
                    instantiate_oldstyle_exceptions = True,
                ))
        self.service = AngrService

    def run(self):
        ThreadedServer(self.service, port=self.port, hostname=self.host).start()
