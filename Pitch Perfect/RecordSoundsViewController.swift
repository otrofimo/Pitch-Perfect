//
//  RecordSoundsViewController.swift
//  Pitch Perfect
//
//  Created by Oleg Trofimov on 5/29/15.
//  Copyright (c) 2015 Oleg Trofimov. All rights reserved.
//

import UIKit
import AVFoundation

class RecordSoundsViewController: UIViewController, AVAudioRecorderDelegate {

    @IBOutlet weak var recordingInProgress: UILabel!
    @IBOutlet weak var stopRecording: UIButton!
    @IBOutlet weak var recordButton: UIButton!
    @IBOutlet weak var pauseButton: UIButton!
    @IBOutlet weak var tapToRecord: UILabel!

    var audioRecorder : AVAudioRecorder!
    var recordedAudio: RecordedAudio!
    var paused = false

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func viewWillAppear(animated: Bool) {
        stopRecording.hidden = true
        pauseButton.hidden = true
        recordButton.enabled = true
        tapToRecord.hidden = false
    }
    
    @IBAction func recordAudio(sender: UIButton) {
        tapToRecord.hidden = true
        recordingInProgress.hidden = false
        stopRecording.hidden = false
        pauseButton.hidden = false
        recordButton.enabled = false
        
        if(!paused) {
            let dirPath = NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! String

            let recordingName = "my_audio.wav"
            let pathArray = [dirPath, recordingName]
            let filePath = NSURL.fileURLWithPathComponents(pathArray)
            println(filePath)

            var session = AVAudioSession.sharedInstance()
            session.setCategory(AVAudioSessionCategoryRecord, error: nil)

            audioRecorder = AVAudioRecorder(URL: filePath, settings: nil, error: nil)
            audioRecorder.delegate = self
            audioRecorder.meteringEnabled = true
            audioRecorder.prepareToRecord()
        }
        audioRecorder.record()
    }

    func audioRecorderDidFinishRecording(recorder: AVAudioRecorder!, successfully flag: Bool) {
        if(flag) {
            recordedAudio = RecordedAudio(filePathUrl: recorder.url, title: recorder.url.lastPathComponent!)
            self.performSegueWithIdentifier("stopRecording", sender: recordedAudio)
        }
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if(segue.identifier == "stopRecording") {
            let playSoundsVC: PlaySoundsViewController = segue.destinationViewController as! PlaySoundsViewController
            let data = sender as! RecordedAudio
            playSoundsVC.receivedAudio = data
        }
    }
    
    @IBAction func pauseRecordAudio(sender: UIButton) {
        recordingInProgress.hidden = true
        tapToRecord.hidden = false
        audioRecorder.pause()
        recordButton.enabled = true
        paused = true
    }

    @IBAction func stopRecordAudio(sender: UIButton) {
        recordingInProgress.hidden = true
        audioRecorder.stop()
        var audioSession = AVAudioSession.sharedInstance()
        audioSession.setActive(false, error: nil)
    }
}

