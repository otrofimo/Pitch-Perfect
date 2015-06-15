//
//  PlaySoundsViewController.swift
//  Pitch Perfect
//
//  Created by Oleg Trofimov on 6/3/15.
//  Copyright (c) 2015 Oleg Trofimov. All rights reserved.
//

import UIKit
import AVFoundation

class PlaySoundsViewController: UIViewController {

    var audioPlayer : AVAudioPlayer!
    var receivedAudio : RecordedAudio!
    var audioEngine: AVAudioEngine!
    var audioFile: AVAudioFile!

    let darthVaderPitch: Float = -1000
    let chipmunkPitch: Float   = 1000
    let largeRoomPitch: Float  = 100
    
    override func viewDidLoad() {
        super.viewDidLoad()
        AVAudioSession.sharedInstance().setCategory(AVAudioSessionCategoryPlayback, error: nil)
        audioPlayer = AVAudioPlayer(contentsOfURL: receivedAudio.filePathUrl, error: nil)
        audioPlayer.enableRate = true
        audioEngine = AVAudioEngine()
        audioFile = AVAudioFile(forReading: receivedAudio.filePathUrl, error: nil)
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation
`
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

    @IBAction func stopAudio(sender: UIButton) {
        audioPlayer.stop()
    }

    func playAudioWithVariableRate(rate: Float) {
        audioPlayer.stop()
        audioPlayer.currentTime = 0.0
        audioPlayer.rate = rate
        audioPlayer.play()
    }
    
    @IBAction func playSlowAudio(sender: UIButton) {
        playAudioWithVariablePitch(0.5)
    }

    @IBAction func playFastAudio(sender: UIButton) {
        playAudioWithVariablePitch(2.0)
    }
    
    func playAudioWithVariableEffect(effect: AVAudioUnit) {
        audioPlayer.stop()
        audioEngine.stop()
        audioEngine.reset()

        var audioPlayerNode = AVAudioPlayerNode()
        audioEngine.attachNode(audioPlayerNode)

        audioEngine.attachNode(effect)
        
        audioEngine.connect(audioPlayerNode, to: effect, format: nil)
        audioEngine.connect(effect, to: audioEngine.outputNode, format: nil)
        
        audioPlayerNode.scheduleFile(audioFile, atTime: nil, completionHandler: nil)
        audioEngine.startAndReturnError(nil)
        
        audioPlayerNode.play()
    }

    func playAudioWithVariablePitch(pitch: Float) {
        var pitchEffect = AVAudioUnitTimePitch()
        pitchEffect.pitch = pitch
        playAudioWithVariableEffect(pitchEffect)
    }

    func playAudioWithVariableReverb(wetDryMix: Float) {
        var reverbEffect = AVAudioUnitReverb()
        reverbEffect.wetDryMix = 100
        playAudioWithVariableEffect(reverbEffect)
    }

    @IBAction func playDarthVaderAudio(sender: UIButton) {
        playAudioWithVariablePitch(darthVaderPitch)
    }

    @IBAction func playChipmunkAudio(sender: UIButton) {
        playAudioWithVariablePitch(chipmunkPitch)
    }

    @IBAction func playReverbAudio(sender: UIButton) {
        playAudioWithVariableReverb(largeRoomPitch)
    }
    
    
}
